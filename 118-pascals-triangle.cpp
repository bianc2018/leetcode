/*
* ����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�

�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return { {1} };
        if (numRows == 2)
            return { {1},{1,1} };
        vector<vector<int>> res({ {1},{1,1} });
        for (int i = 3; i <= numRows; ++i)
        {
            //����
            int col_num = i;
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j < col_num - 1; ++j)
            {
                line.push_back(res[i - 1-1][j - 1] + res[i - 1-1][j]);
            }
            line.push_back(1);
            res.push_back(line);
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    auto res = s.generate(5);
    return 0;
}