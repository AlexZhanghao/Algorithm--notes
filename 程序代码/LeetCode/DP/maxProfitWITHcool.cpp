#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(3,0));

        //0 表示不持股；
        dp[0][0]=0;
        //1 表示持股；
        dp[0][1]=-prices[0];
        //2 表示处在冷冻期。
        dp[0][2]=0;

        //不持股可由不持股和持股卖掉转换过来
        //持股可由持股和冷冻期买股票转换过来
        //因为股票卖掉后进入一天冷冻期，此时已经进入不持股的状态，所以冷冻期只能由不持股转换过来
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][2]-prices[i]);
            dp[i][2]=dp[i-1][0];
        }

        return max(dp[n-1][0],dp[n-1][2]);
    }
};

//采用滚动数组进行优化
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(2,vector<int>(3,0));

        //0 表示不持股；
        dp[0][0]=0;
        //1 表示持股；
        dp[0][1]=-prices[0];
        //2 表示处在冷冻期。
        dp[0][2]=0;

        for(int i=1;i<n;++i){
            dp[i&1][0]=max(dp[(i-1)&1][0],dp[(i-1)&1][1]+prices[i]);
            dp[i&1][1]=max(dp[(i-1)&1][1],dp[(i-1)&1][2]-prices[i]);
            dp[i&1][2]=dp[(i-1)&1][0];
        }

        return max(dp[(n-1)&1][0],dp[(n-1)&1][2]);
    }
};