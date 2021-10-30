/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

*/
#include <vector>
using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row_num = matrix.size();
        if (0 == row_num)
            return false;
        int col_num = matrix[0].size();
        if (0 == col_num)
            return false;

        //右上角
        int i = 0;
        int j = col_num - 1;
        while (j >= 0 && i < row_num)
        {
            if (target == matrix[i][j])
            {
                return true;
            }
            else if (target > matrix[i][j])
            {
                //行加一
                ++i;
            }
            else
            {
                //列减一
                --j;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>({ 1,4}));
    matrix.push_back(vector<int>({ 2,5 }));
   /* matrix.push_back(vector<int>({ 1,   4,  7, 11, 15 }));
    matrix.push_back(vector<int>({ 2,   5,  8, 12, 19 }));
    matrix.push_back(vector<int>({ 3,   6,  9, 16, 22 }));
    matrix.push_back(vector<int>({ 10, 13, 14, 17, 24 }));
    matrix.push_back(vector<int>({ 18, 21, 23, 26, 30 }));*/
    Solution s;
    auto ret = s.findNumberIn2DArray(matrix, 2);
    return 0;
}