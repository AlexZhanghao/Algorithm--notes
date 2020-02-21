#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int across=grid.size();
        int vertical=grid[0].size();
        vector<int> a(vertical);
        vector<vector<int>> dp(across,a);

        //这里应该将最后一排和一列都初始化一下，不然会出现vector超范围
        dp[across-1][vertical-1]=grid[across-1][vertical-1];
        for(int i=vertical-2;i>-1;--i){
            dp[across-1][i]=dp[across-1][i+1]+grid[across-1][i];
        }
        for(int i=across-2;i>-1;--i){
            dp[i][vertical-1]=dp[i+1][vertical-1]+grid[i][vertical-1];
        }

        for(int i=across-2;i>-1;--i){
            for(int j=vertical-2;j>-1;--j){
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }

    int min(int a,int b){
        return (a<b)?a:b;
    }
};