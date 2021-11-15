/*
* 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。 
*/
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int num1=0, num2 = 0;
        for (auto& n : nums)
        {
            num1 = n ^ num1;
        }
        int flag = num1 & (-num1);
        for (auto& n : nums)
        {
            if(n&flag)
                num2 = n ^ num2;
        }

        return { num1^ num2,num2 };
    }
};

int main(int argc, char* argv[])
{
    //nums = [4,1,4,6]
    vector<int> nums = {4,1,4,6};
    Solution s;
    auto ret = s.singleNumbers(nums);
    printf("ret = %d,%d\n", ret[0], ret[1]);
}