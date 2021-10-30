/*
* ���ַ��� s ���ҳ���һ��ֻ����һ�ε��ַ������û�У�����һ�����ո� s ֻ����Сд��ĸ��
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

            if (chars_map[s[i]] == -1) //����
                chars_map[s[i]] = i;
            else //��γ���
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