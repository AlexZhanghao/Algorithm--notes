#include<vector>
#include<algorithm>

using namespace std;

//这里的方法有点味道，感觉这属于一类问题(更像是双指针)
//不过确实没用到动态规划，因为问题其实并不符合最优子结构
int maxProfit(vector<int>& prices) {
    int n=prices.size();

    if(n==0||n==1){
        return 0;
    }

    int max_profit=0;
    int min_price=prices[0];

    for(int i=1;i<n;++i){
        if(prices[i]<min_price){
            min_price=prices[i];
        }
        if(prices[i]-min_price>max_profit){
            max_profit=prices[i]-min_price;
        }
    }

    return max_profit;
}

//这里使用在评论区中白嫖到的所谓股票问题通杀解法来处理下这题
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case: dp[-1][0] = 0, dp[-1][1] = -infinity
        int dp_i_0 = 0, dp_i_1 =-INT_MAX;
        for (int i = 0; i < n; i++) {
            // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            // dp[i][1] = max(dp[i-1][1], -prices[i])
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};