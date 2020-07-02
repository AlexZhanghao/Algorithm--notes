#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(n==0&&amount==0) return 1;
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        //dp[0][0] 的值应该设置为 1，它虽然没有意义，但是是一个被参考的值，
        //原因是：当 dp[i - 1][j - k * coins[i]] 的第 2 个坐标 j - k * coins[i] == 0 成立的时候，k 个硬币 coin[i] 就恰好成为了一种组合，
        //因此，dp[0][0] = 1。
        dp[0][0]=1;

        //初始化第一行
        for(int j=coins[0];j<amount+1;j+=coins[0]){
            dp[0][j]=1;
        }
        
        //dp[i][j]：硬币列表的前缀子区间 [0, i] 能够凑成总金额 j 的组合数。
        for(int i=1;i<n;++i){
            for(int j=0;j<amount+1;++j){
                int k=0;
                while(j-k*coins[i]>=0){
                    dp[i][j]+=dp[i-1][j-k*coins[i]];
                    ++k;
                }
            }
        }

        return dp[n-1][amount];
    }
};

//在上述解的基础上，经过无穷级数的运算可以得到如下状态转移方程：
//dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
//于是解可以被优化为
class Solution2 {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(n==0&&amount==0) return 1;
        if(n==0) return 0;
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        //dp[0][0] 的值应该设置为 1，它虽然没有意义，但是是一个被参考的值，
        //原因是：当 dp[i - 1][j - k * coins[i]] 的第 2 个坐标 j - k * coins[i] == 0 成立的时候，k 个硬币 coin[i] 就恰好成为了一种组合，
        //因此，dp[0][0] = 1。
        dp[0][0]=1;

        //初始化第一行
        for(int j=coins[0];j<amount+1;j+=coins[0]){
            dp[0][j]=1;
        }
        
        //dp[i][j]：硬币列表的前缀子区间 [0, i] 能够凑成总金额 j 的组合数。
        for(int i=1;i<n;++i){
            for(int j=0;j<amount+1;++j){
                dp[i][j]=dp[i-1][j];
                if(j-coins[i]>=0){
                    dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        }

        return dp[n-1][amount];
    }
};

//在解2的基础上还可以进行空间的优化，因为当前状态行的值，只和上一行的状态值相关
class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        if(n==0&&amount==0) return 1;
        if(n==0) return 0;
        vector<int> dp(amount+1,0);

        dp[0]=1;

        //初始化第一行
        for(int j=coins[0];j<amount+1;j+=coins[0]){
            dp[j]=1;
        }
        
        for(int i=1;i<n;++i){
            for(int j=coins[i];j<amount+1;++j){
                dp[j]+=dp[j-coins[i]];
            }
        }

        return dp[amount];
    }
};