#include<iostream>
#include<vector>

using namespace std;

//这里在求i时需要把1~i-1加起来然后再加1，而i-1则等于1~i-2加起来加1，故i=2*(i-1)
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number+1,0);
        dp[1]=1;
        dp[2]=2;     
        for(int i=3;i<number+1;++i){
            dp[i]=2*dp[i-1];
        }
        return dp[number];
    }
};