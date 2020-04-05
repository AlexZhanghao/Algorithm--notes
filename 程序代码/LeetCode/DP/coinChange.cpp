#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//动态规划，自底向上
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> step(amount+1,0);
        for(int i=1;i<=amount;++i){
            int minstep=INT_MAX;
            for(int j=0;j<coins.size();++j){
                if(i-coins[j]>=0&&step[i-coins[j]]!=-1){
                    if(step[i-coins[j]]<minstep){
                        minstep=step[i-coins[j]];
                    }
                }
            }
            if(minstep!=INT_MAX){
                step[i]=minstep+1;
            }
            else{
                step[i]=-1;
            }           
        }
        return step[amount];
    }
};



//官方给的自顶向下版本
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        count.resize(amount);
        return dp(coins, amount);
    }
private:
    vector<int>count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem - 1] != 0) return count[rem - 1];
        int Min = INT_MAX;
        for (int coin:coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }
};



//copy的答友的贪心算法，讲真，他写的有点东西（自己写的过于冗余且有弊端，未能通过...）
class Solution3 {
void coinChange(vector<int>& coins, int amount, int c_index, int count, int& ans)
{
    if (amount == 0)
    {
        ans = min(ans, count);
        return;
    }
    if (c_index == coins.size()) return;

    for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
    {
        coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
    }
}

int coinChange(vector<int>& coins, int amount)
{
    if (amount == 0) return 0;
    sort(coins.rbegin(), coins.rend());
    int ans = INT_MAX;
    coinChange(coins, amount, 0, 0, ans);
    return ans == INT_MAX ? -1 : ans;
}
}；