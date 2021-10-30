/*
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������

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

        //���Ͻ�
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
                //�м�һ
                ++i;
            }
            else
            {
                //�м�һ
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