/*
* 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    static bool cmp(const int& t1, const int& t2)
    {
        //说当比较的两个数相等时，应该返回false
        if (t1 == t2)
            return false;

        const int buff_size = 64;
        char buff1[buff_size], buff2[buff_size];
        sprintf(buff1, "%d%d", t1, t2);
        sprintf(buff2, "%d%d", t2, t1);
        for (int i = 0; i < buff_size; ++i)
        {
            if (buff1[i] > buff2[i])
            {
                return false;
            }
            else if (buff1[i] < buff2[i])
            {
                return true;
            }
            else if (buff1[i] ==0)
            {
                return false;
            }
        }
        return false;
    }
    bool Sort(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end(), Solution::cmp);
        return true;
    }
public:
    string minNumber(vector<int>& nums) {
        //
        Sort(nums);
        string str;
        for (auto& n : nums)
        {
            str += std::to_string(n);
        }
        return str;
    }
};
int main(int argc, char* argv[])
{
    vector<int> nums = { 3,30,34,5,9 };
    Solution s;
    printf("ret=%s\n", s.minNumber(nums).c_str());
}