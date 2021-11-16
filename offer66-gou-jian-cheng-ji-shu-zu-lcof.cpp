/*
* 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其
中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int size = a.size();
        int val = 1;
        vector<int> res1(size, 1), res2(size, 1);
        for (int i = 0; i < size; ++i)
        {
            res1[i] = val;
            val *= a[i];
        }
        val = 1;
        for (int i = size-1; i >=0; --i)
        {
            res1[i] *= val;
            val *= a[i];
        }
        return res1;
    }
};

void printvec(vector<int>& a)
{
    for (int i = 0; i < a.size(); ++i)
        if (i == 0)
            printf("(%d", a[i]);
        else
            printf(",%d", a[i]);
    printf(")\n");
    return;
}
int main(int argc, char* argv[])
{
    vector<int> a = { 1,2,3,4,5 };
    Solution s;
    printvec(s.constructArr(a));
    return 0;
}