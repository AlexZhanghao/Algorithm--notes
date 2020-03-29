#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
       int dp[1000][1000];
        for (int i = 0; i < N; ++i) dp[i][i] = 1;
        //步进
        for (int len = 2; len <= N; ++len) {
            //遍历开始
            for (int i = 0; i + len - 1 < N; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][N - 1];
    }
};

//这里将记录的dp降成了一维，但思路并没有变化
class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        int N = s.size();
        vector<int> dp(N, 1);
        for (int i = N - 1; i >= 0; --i) {
            int prev = 0;
            for (int j = i + 1; j < N; ++j) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = 2 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                //注意这里，它现在等于是一步步的向外扩展，所以只需要关注上一次的长度即可
                prev = temp;
            }
        }
        return dp[N - 1];
    }
};