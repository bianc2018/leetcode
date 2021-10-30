/*
* 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
*/
#include <string>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        const int map_size = 256;
        int chars_map[map_size];
        memset(chars_map, -1, sizeof(chars_map));

        for (int i = 0; i < s.size(); ++i)
        {

            if (chars_map[s[i]] == -1) //单次
                chars_map[s[i]] = i;
            else //多次出现
                chars_map[s[i]] == -2;
        }

        int index = -1;
        for (int i = 0; i < map_size; ++i)
        {
            if (chars_map[i] != -1 && chars_map[i] != -2)
            {
                if (-1 == index || chars_map[i] < index)
                {
                    index = chars_map[i];
                }
            }
        }
        if (index == -1)
            return ' ';
        return s[index];
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    printf("%c\n", s.firstUniqChar("loveleetcode"));
    return 0;
}