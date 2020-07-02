#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<1) return 0;
        vector<int> dp(n,0);
        dp[0]=1;
        int maxlen=1;
        for(int i=1;i<n;++i){
            int len=0;
            for(int j=i-1;j>=0;--j){
                if(nums[j]<nums[i]) len=max(len,dp[j]+1);
            }
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};