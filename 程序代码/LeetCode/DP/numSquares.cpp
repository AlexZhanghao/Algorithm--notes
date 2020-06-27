#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n<1) return 0;
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<n+1;++i){
            int min_squ=INT_MAX;
            for(int j=1;i-j*j>=0;++j){
                if(dp[i-j*j]!=-1){
                    min_squ=min(min_squ,dp[i-j*j]+1);
                }
            }
            if(min_squ!=INT_MAX) dp[i]=min_squ;
            else dp[i]=-1;
        }              
        return dp[n];
    }
};