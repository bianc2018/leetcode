/*
* 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //value int
        unordered_map<int, int> hash_table;

        int x1 = 0, x2 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end())
            {
                return { it->second,i };
            }
            hash_table[nums[i]] = i;
        }
        return { x1,x2 };
    }
};

int main(int argc, char* argv[])
{
    /*
    * [2,7,11,15]
        9
    */
    vector<int> data;
    data.push_back(2);
    data.push_back(7);
    data.push_back(11);
    data.push_back(15);
    Solution s;
    vector<int> res =s.twoSum(data, 9);
    printf("result [%d,%d]\n", res[0], res[1]);
    return 0;
}