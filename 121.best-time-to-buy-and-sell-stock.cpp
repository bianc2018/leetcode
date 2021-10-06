/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int buy = prices[0];
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] > buy)
            {
                if (prices[i] - buy > max)
                {
                    max = prices[i] - buy;
                }
            }
            else
            {
                buy = prices[i];
            }
           
        }
        return max;
    }
};

int main(int argc, char* argv[])
{
    //[7,1,5,3,6,4]
    vector<int> prices;
   /* prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);*/

    //[7,6,4,3,1]
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);

    Solution s;
    printf("maxProfit %d\n", s.maxProfit(prices));
    return 0;
}