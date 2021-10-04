/*
* ����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
  �������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //�������ټ���
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);

    Solution s;
    if (s.containsDuplicate(data))
        printf("is true");
    else
        printf("is false");
    return 0;
}