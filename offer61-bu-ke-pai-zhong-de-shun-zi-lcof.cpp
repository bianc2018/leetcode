/*
从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int zero_count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                ++zero_count;
            }
            else if (i != 0&& nums[i - 1]!=0)
            {
                int cmp = nums[i] - nums[i - 1];
                if (cmp == 0)
                {
                    return false;
                }
                else if (cmp > 1)
                {
                    zero_count -= (cmp - 1);
                    if (zero_count < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
int main(int argc, char* argv[])
{
    vector<int> nums = { 0,0,8,5,4 };
    Solution s;
    printf("ret=%s\n", s.isStraight(nums)?"true":"false");
}