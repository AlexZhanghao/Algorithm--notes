#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//标准的暴力拆解，时间上很差，但大跌眼镜的是空间上居然是100%
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<1) return s;
        int longestpal=1;
        string out;
        out+=s[0];
        int l=0,r=0,start=0;
        while(l<n){
            r=l+longestpal;
            while(r<n){
                if(s[l]==s[r]){
                    int left=l+1,right=r-1;
                    while(left<right){
                        if(s[left]!=s[right]) break;
                        ++left;--right;
                    }
                    if(s[left]==s[right]){
                        if(longestpal<(r-l+1)){
                            longestpal=r-l+1;
                            start=l;
                        }
                        // out.clear();
                        // for(int i=l;i<=r;++i){
                        //     out+=s[i];
                        // }
                    }
                }
                ++r;
            }
            ++l;
        }
        out.clear();
        for(int i=start;i<=start+longestpal-1;++i) out+=s[i];
        return out;
    }
};

//DP
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<1) return s;
        int longestpal=1,start=0;
        string out;
        vector<vector<int>> DP(n,vector<int>(n,0));
        for(int j=1;j<n;++j){
            for(int i=0;i<j;++i){
                if(s[i]==s[j]){
                    if((j-i)==1||(j-i)==2) DP[i][j]=1;
                    else{
                        DP[i][j]=DP[i+1][j-1];
                    }
                }
                if(DP[i][j]==1&&(j-i+1)>longestpal){
                    longestpal=j-i+1;
                    start=i;
                }
            }
        }

        for(int i=start;i<=start+longestpal-1;++i) out+=s[i];
        return out;
    }
};