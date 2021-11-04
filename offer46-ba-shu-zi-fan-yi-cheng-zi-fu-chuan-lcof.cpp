/*
����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include <cstdio>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        char str[64] = { 0 };
        sprintf(str, "%d", num);

        int fn_1 = 1, fn_2 = 1, fn = 1;
        for (int i = 1; str[i] != 0; ++i)
        {
            int ch = (str[i - 1] - '0') * 10+ (str[i] - '0');
            if (ch >=10&&ch <= 25)
            {
                fn = fn_1 + fn_2;
                fn_2 = fn_1;
                fn_1 = fn;
            }
            else
            {
                fn = fn_1;
                fn_2 = fn_1;
                fn_1 = fn;
            }
        }
        return fn;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("ret=%d\n", s.translateNum(506));
    return 0;
}