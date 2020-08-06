#include<iostream>
#include<string>
#include<vector>

using namespace std;

//回溯法
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ret;
        vector<string> a;
        dfs(ret,a,s,0,n);
        return ret;
    }

	void dfs(vector<vector<string>> &ret, vector<string> &a, string s, int cur, int len) {
		int n = s.size();
		for (int i = 1; i < n + 1; ++i) {
			string b = s.substr(0, i);
			if (isPalindrome(b)) {
				a.push_back(b);
				cur += i;
				if (cur >= len) ret.push_back(a);
				else {
					string c = s.substr(i, n - i + 1);
					dfs(ret, a, c, cur, len);
				}
				cur -= i;
				a.pop_back();
			}
		}
	}

    bool isPalindrome(string s){
        int n=s.size();
        int left=0,right=n-1;
        while(left<right){
            if(s[left]!=s[right]) return false;
            else{
                ++left;
                --right;
            }
        }
        return true;
    }
};

//使用动态规划进行空间换时间的优化
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>> ret;
        vector<string> a;

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i) dp[i][i]=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(s[i]==s[j]){
                    if(i==j+1){
                        dp[i][j]=1;
                        continue;
                    }
                    if(dp[i+1][j-1]==1) dp[i][j]=1;
                    else dp[i][j]=-1;
                }
            }
        }

        dfs(ret,a,s,0,n,dp);
        return ret;
    }

	void dfs(vector<vector<string>> &ret, vector<string> &a, string s, int cur, int len,vector<vector<int>>& dp) {
		int n = s.size();
		for (int i = 1; i < n + 1; ++i) {
			string b = s.substr(0, i);
			if (dp[cur][cur+i-1]==1) {
				a.push_back(b);
				cur += i;
				if (cur >= len) ret.push_back(a);
				else {
					string c = s.substr(i, n - i + 1);
					dfs(ret, a, c, cur, len,dp);
				}
				cur -= i;
				a.pop_back();
			}
		}
	}
};