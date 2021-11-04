/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
*/
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        int max_len = 0;
        int count = 0;
        unordered_map<char, int> check_map;
        for (int i = 0; i < s.size();)
        {
            auto it = check_map.find(s[i]);
            if (it != check_map.end())
            {
                //找到了重复的
                if (count > max_len)
                    max_len = count;

                i = it->second + 1;
                check_map.clear();
                count = 0;
            }
            else
            {
                check_map.insert(make_pair(s[i], i));
                ++count;
                ++i;
            }
        }
        if (count > max_len)
            max_len = count;
        return max_len;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1)
            return s.size();

        int max_len = 0;
        int* dp = new int[s.size()];
        dp[0] = 1;

        int last_one[256];
        memset(last_one, -1, sizeof(int) * 256);
        last_one[s[0]] = 0;

        int i = -1;
        for (int j = 1; j < s.size(); ++j)
        {
            if (last_one[s[j]] == -1)
            {
                dp[j] = dp[j - 1] + 1;
            }
            else
            {
                i = last_one[s[j]];
                if(j-i> dp[j - 1])
                    dp[j] = dp[j - 1] + 1;
                else
                    dp[j] = j-i;
            }
            if (max_len < dp[j])
                max_len = dp[j];
            last_one[s[j]] = j;
        }
        delete[]dp;
        return max_len;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("ret=%d\n", s.lengthOfLongestSubstring("abba"));
    return 0;
}