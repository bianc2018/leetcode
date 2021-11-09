/*
* 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，
它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

*/

#include <cstdio>
#include <memory>
using namespace std;

class Solution {
    bool canmoving(int i, int j, int k)
    {
        int sum = 0;
        while (i)
        {
            sum += i % 10;
            i /= 10;
        }
        while (j)
        {
            sum += j % 10;
            j /= 10;
        }
        if (sum <= k)
            return true;
        else
            return false;
    }
    int dps(int m, int n, int i, int j, bool* is_used_map, int k) {
        if (i >= m || j >= n || i < 0 || j < 0)
            return 0;
        if (is_used_map[i * m + j] || false == canmoving(i, j, k))
            return 0;
        int count = 1;
        is_used_map[i * m + j] = true;
        count += dps(m, n, i + 1, j, is_used_map, k);
        count += dps(m, n, i - 1, j, is_used_map, k);
        count += dps(m, n, i, j - 1, is_used_map, k);
        count += dps(m, n, i, j + 1, is_used_map, k);
        return count;
    }
public:
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0)
            return 0;
        bool* is_used_map = new bool[m * n];
        memset(is_used_map, false, m * n * sizeof(bool));
        int count = dps(m, n, 0, 0, is_used_map, k);
        delete[]is_used_map;
        return count;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("ret = %d\n", s.movingCount(3, 2, 17));
    return 0;
}