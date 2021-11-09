/*
* ������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ���
��ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
�������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

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