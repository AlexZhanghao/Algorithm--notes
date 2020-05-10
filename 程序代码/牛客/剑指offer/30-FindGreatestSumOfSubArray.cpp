#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<vector<int>> dp(array.size(),vector<int>{0,0});
        dp[0][1]=array[0];
        int max_sub=array[0];
        for(int i=1;i<array.size();++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1])+array[i];
            dp[i][1]=array[i];
            max_sub=max(max_sub,max(dp[i][0],dp[i][1]));
        }
        return max_sub;
    }
};