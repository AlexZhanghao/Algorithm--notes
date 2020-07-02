#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        if(wordDict.size()==0) return false;
        vector<int> dp(n,0);
        unordered_set<string> us;
        for(int i=0;i<wordDict.size();++i){
            us.insert(wordDict[i]);
        }

        for(int i=0;i<n;++i){
            if(us.count(s.substr(0,i+1))) dp[i]=1;
            else{
                for(int j=0;j<i;++j){
                    if(dp[j]&&us.count(s.substr(j+1,i-j+1))){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};