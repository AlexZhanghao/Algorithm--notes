#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();

        //dp[i][j] 代表字符串 s 中前 i 个字符和 p 中前 j 个字符是否匹配
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        for(int j=2;j<=n2;++j) dp[0][j]=dp[0][j-2]&&p[j-1]=='*';

        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){
                int m=i-1,n=j-1;
                if(s[m]==p[n]||p[n]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[n]=='*'){
                    dp[i][j]=dp[i][j-2]||((p[n-1]==s[m]||p[n-1]=='.')&&dp[i-1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        s=" "+s;p=" "+p;
        //dp[i][j] 代表字符串 s 中前 i 个字符和 p 中前 j 个字符是否匹配
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=1;
        for(int j=2;j<=n2;++j) dp[0][j]=dp[0][j-2]&&p[j-1]=='*';

        for(int i=1;i<=n1;++i){
            for(int j=1;j<=n2;++j){                
                if(s[i]==p[j]||p[j]=='.') dp[i][j]=dp[i-1][j-1];
                else if(p[j]=='*'){
                    dp[i][j]=dp[i][j-2]||((p[j-1]==s[i]||p[j-1]=='.')&&dp[i-1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};