/*
* 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int pushed_index = 0;
        for (int i = 0; i < popped.size();)
        {
            if (!st.empty() && st.top() == popped[i])
            {
                st.pop();
                ++i;
            }
            else
            {
                if (pushed_index >= pushed.size())
                    return false;

                if (pushed[pushed_index] != popped[i])
                {
                    st.push(pushed[pushed_index]);
                    ++pushed_index;
                }
                else//等于的直接抵消
                {
                    ++i;
                    ++pushed_index;
                }
            }

        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,2,1 };
    Solution s;

    printf("ret=%s\n", s.validateStackSequences(pushed, popped) ? "true" : "false");
    
}