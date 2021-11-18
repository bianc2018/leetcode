/*
* 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
*/
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int row_start = 0, row_end = matrix.size() - 1;
        if (row_end < 0)
            return res;
        int col_start = 0, col_end = matrix[0].size() - 1;
        int need = matrix.size() * matrix[0].size();
        while (res.size() < need)
        {
            //水平一行
            for (int i = col_start; i <= col_end; ++i)
                res.push_back(matrix[row_start][i]);
            ++row_start;
            if (res.size() >= need)
                break;

            //尾一列
            for (int i = row_start; i <= row_end; ++i)
                res.push_back(matrix[i][col_end]);
            --col_end;
            if (res.size() >= need)
                break;

            //尾一行
            for (int i = col_end; i >= col_start; --i)
                res.push_back(matrix[row_end][i]);
            --row_end;
            if (res.size() >= need)
                break;

            for (int i = row_end; i >= row_start; --i)
                res.push_back(matrix[i][col_start]);
            ++col_start;
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    Solution s;
    auto res = s.spiralOrder(matrix);
    for (auto& d : res)
    {
        printf("%d,", d);
    }
    printf("\n");
}