/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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