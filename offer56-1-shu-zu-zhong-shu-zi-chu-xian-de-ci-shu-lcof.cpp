/*
* һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)�� 
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