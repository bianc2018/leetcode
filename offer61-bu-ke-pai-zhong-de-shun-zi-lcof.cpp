/*
�����ɸ��˿���������� 5 ���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С��Ϊ 0 �����Կ����������֡�A ������Ϊ 14��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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