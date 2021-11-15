/*
* 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
*/
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    int singleNumbers(vector<int>& nums) {
        int bit_count[32] = { 0 };
        for (auto& n : nums)
        {
            for (int i = 0; i < 32; ++i)
                if (n & (1 << i)) ++bit_count[i];
        }
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (bit_count[i] % 3 != 0)
            {
                res |= (1 << i);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    //nums = [4,1,4,6]
    vector<int> nums = { 3,4,3,3 };
    Solution s;
    printf("ret = %d\n", s.singleNumbers(nums));
}