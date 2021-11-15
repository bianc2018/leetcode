/*
* ��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�
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