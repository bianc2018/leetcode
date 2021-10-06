/*
* 
* 给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2,2]
示例 2:

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[4,9]

说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void print(vector<int>& res)
    {
        printf("[");
        for (int i = 0; i < res.size(); ++i)
        {
            if (0 == i)
                printf("%d", res[i]);
            else
                printf(",%d", res[i]);
        }
        printf("]");
    }
public:
    unordered_map<int, int> make_map(vector<int>& nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = map.find(nums[i]);
            if (it != map.end())
                it->second++;
            else
                map.insert(make_pair(nums[i], 1));
        }
        return map;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> map1 = make_map(nums1),
            map2 = make_map(nums2);
        
        for (auto& it1 : map1)
        {
            auto it2 = map2.find(it1.first);
            if (it2 != map2.end())
            {
                int t = it1.second > it2->second ? it2->second : it1.second;
                for (int i = 0; i < t; ++i)
                    res.push_back(it1.first);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    //nums1 = [1,2,2,1], nums2 = [2,2]
    vector<int> nums1,nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(2);
    nums1.push_back(1);

    nums2.push_back(2);
    nums2.push_back(2);

    Solution s;
    auto res = s.intersect(nums1, nums2);
    s.print(res);
    return 0;
}