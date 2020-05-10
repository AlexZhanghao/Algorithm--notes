#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        vector<int> dp(number+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<number+1;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[number];
    }
};