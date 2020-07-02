#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        if(row==0) return 0;
        int col=grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i,i<row;++i){
            for(int j=0;j<col;++j){
                if(i==0&&j==0) continue;
                if(i==0) dp[i][j]=grid[i][j]+dp[i][j-1];
                else if(j==0) dp[i][j]=grid[i][j]+dp[i-1][j];
                else{
                    dp[i][j]=grid[i][j]+min(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[row-1][col-1];
    }
};