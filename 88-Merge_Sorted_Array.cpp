/*
* 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;

        for (int i = 0; i < m; ++i)
        {
            if (nums1[i] > nums2[0])
            {
                int temp = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = temp;

                for (int j = 1; j < n; ++j)
                {
                    if (nums2[j - 1] > nums2[j])
                    {
                        //交换
                        int temp = nums2[j - 1];
                        nums2[j - 1] = nums2[j];
                        nums2[j] = temp;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            nums1[i + m] = nums2[i];
        }
    }
};