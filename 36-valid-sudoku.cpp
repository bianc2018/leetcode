/*
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isUseX[9][9];
        bool isUseY[9][9];
        bool isBlock[9][9];
        memset(isUseX,0, sizeof(isUseX));
        memset(isUseY, 0, sizeof(isUseY));
        memset(isBlock, 0, sizeof(isBlock));

        for (int x = 0; x < board.size(); ++x)
        {
            for (int y = 0; y < board[x].size(); ++y)
            {
                if (board[x][y] == '.')
                    continue;
                int num = board[x][y] - '1';
                int blockIndex = (x / 3) * 3 + y / 3;
                if (isUseX[x][num]
                    || isUseY[y][num]
                    || isBlock[blockIndex][num])
                {
                    return false;
                }
                else
                {
                    isUseX[x][num] = true;
                    isUseY[y][num] = true;
                    isBlock[blockIndex][num] = true;
                }

            }
        }

        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char>> board;
    vector<char> line = { '5','3','.','.','7','.','.','.','.' };
    board.push_back(line);
    Solution s;
    if (s.isValidSudoku(board))
        printf("isValidSudoku true\n");
    else
        printf("isValidSudoku false\n");

    return true;
}