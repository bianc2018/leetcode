/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
输入：nums = [1]
输出：1
*/

#include <vector>
using namespace std;

class Solution {
public:
    
    //自己的解法 超时
    int maxSubArraya(vector<int>& nums) {
        int size = nums.size();
        int max = -1000000;
        int mi = 0, mj = 0;
        bool ini_flag = true;
        //标识 i->j的累加
        int* map = new int[size*size];
        memset(map, 0, sizeof(int) * size * size);

        for (int j = 0; j < size; ++j)
        {
            //j->j的累加
            map[j * size + j] = nums[j];
            if (ini_flag||map[j * size + j] > map[mi * size + mj])
            {
                mi = j;
                mj = j;
                ini_flag = false;
            }

            //i->j的累加 = i->j-1的累加+nums[j]
            for (int i = 0; i < j; ++i)
            {
                map[i * size + j] = map[i * size + j - 1] + nums[j];
                if (map[i * size + j] > map[mi * size + mj])
                {
                    mi = i;
                    mj = j;
                }
            }
        }
        return map[mi*size+mj];
    }
    
    //官方解法
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto& x : nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }

};
int main(int argc, char* argv[])
{
    //[-2,1,-3,4,-1,2,1,-5,4]
    vector<int> data;
    data.push_back(1);
    data.push_back(10);
    data.push_back(-1);
    data.push_back(9);
    /*data.push_back(-2);
    data.push_back(1);
    data.push_back(-3);
    data.push_back(4);
    data.push_back(-1);
    data.push_back(2);
    data.push_back(1);
    data.push_back(-5);
    data.push_back(4);*/

    Solution s;

    printf("maxSubArray is %d\n", s.maxSubArray(data));

    return 0;
}