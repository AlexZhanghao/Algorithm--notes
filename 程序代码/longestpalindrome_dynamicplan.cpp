#include<iostream>
#include<string>
#include<vector>

#define INT_MAX 0x7fffffff

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>>  dp(n,vector<int>(n));

        if(n==0||n==1)
            return s;

        int strat_position=0;
        int max_length=0;

        for(int i=0;i<n;++i){
            dp[i][i]=1;
            strat_position=i;
            max_length=1;
        }
        for(int i=0;i<n-1;++i){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                strat_position=i;
                max_length=2;
            }
            else{
                dp[i][i+1]=0;
            }
        }

        for(int l=3;l<n+1;l++){
            for(int i=0;i<n-l+1;i++){
                if(dp[i+1][i+l-2]==1&&s[i]==s[i+l-1]){
                    dp[i][i+l-1]=1;
                    strat_position=i;
                    max_length=l;
                }else{
                    dp[i][i+l-1]=0;
                }
            }
        }

        string longest_palindrome;
        for(int i=strat_position;i<strat_position+max_length;++i){
            longest_palindrome+=s[i];
        }

        return longest_palindrome;
    }
    

};
