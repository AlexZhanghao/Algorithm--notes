#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<number+1;++i){
            //这里dp[i-2]有直接进两步和进两次一步两种方案
            //更正：这里dp[i-1]中已经包含了dp[i-2]进两次一步的方案
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[number];
    }
};

//这里因为每次只用到前面两个数，故可以在空间上改进如下：
class Solution2 {
public:
    int jumpFloor(int number) {
        if(number==1) return 1;
        if(number==2) return 2;        
        int dp1=1,dp2=2;
        for(int i=0;i<number-2;++i){
            int dp=dp1+dp2;
            dp1=dp2;
            dp2=dp;
        }
        return dp2;        
    }
};