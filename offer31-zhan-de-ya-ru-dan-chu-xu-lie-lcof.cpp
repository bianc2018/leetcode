/*
* ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ����磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
                else//���ڵ�ֱ�ӵ���
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