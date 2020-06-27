/******最长回文子串******
LONGEST-PALINDROME(s)
n=s.length
if n==0 || n==1
   return s

let m[1...n,1..n],w[1...n,1..n] be new tables
for i=1 to n
    m[i,i]=1
    w[i,i]=i
for i=1 to n-1
    if s(i)==s(i+1)
       m[i,i+1]=2
       w[i,i]=i
    else
       m[i,i+1]=1;
       w[i,i+1]=i

//遍历所有的奇数项
for i=1 to n
    p=i
    q=i
    l=1
    while p>0 && q<n+1
        if (s(p-1)!=s(q+1))
            m[p,q]=l
            w[p,q]=p
            for j=p-1 to 1
                k=2*i-j
                if k<n+1
                   m[j,k]=l
                   w[j,k]=p
        else
            p=p-1
            q=q+1
            l=l+2
            m[p,q]=l
            w[p,q]=p

//遍历所有的偶数项，只需在遍历奇数的基础上改动下q和l即可
for i=1 to n-1
    p=i
    q=i+1
    l=2
    while p>0 && q<n+1
        if (s(p-1)!=s(q+1))
            m[p,q]=l
            w[p,q]=p
            for j=p-1 to 1
                k=2*i-j
                if k<n+1
                   m[j,k]=l
                   w[j,k]=p
        else
            p=p-1
            q=q+1
            l=l+2
            m[p,q]=l
            w[p,q]=p
******最长回文子串******/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<1) return s;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=1;i<n;++i) dp[i][i]=1;

        int max_len=1;
        int start=0;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(s[i]==s[j]){
                    if(i==j+1) dp[j][i]=2;
                    dp[j][i]=(dp[j+1][i-1]==-1)?-1:(dp[j+1][i-1]+2);

                    if(max_len!=max(max_len,dp[j][i])){
                        max_len=max(max_len,dp[j][i]);
                        start=j;
                    }
                }
                else dp[j][i]=-1;
            }
        }
        
        string out;
        for(int i=start;i<start+max_len;++i) out+=s[i];
        return out;
    }
};