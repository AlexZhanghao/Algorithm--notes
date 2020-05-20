#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/mian-shi-ti-66-gou-jian-cheng-ji-shu-zu-biao-ge-fe/
//这个仁兄用了一样的思路，但是在空间上更优，先正向过一遍装入一个vector，然后反向过的时候直接往正向的vector中乘。
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int asize=A.size();
        if(asize<1) return {};
        vector<vector<int>> dp(2,A);
        dp[0][0]=A[0];
        dp[1][asize-1]=A[asize-1];
        for(int i=1;i<asize-1;++i){
            dp[0][i]=dp[0][i-1]*A[i];
            dp[1][asize-1-i]=dp[1][asize-i]*A[asize-i-1];
        }
        vector<int> B(asize,0);
        B[0]=dp[1][1];
        B[asize-1]=dp[0][asize-2];
        for(int j=1;j<asize-1;++j){
            B[j]=dp[0][j-1]*dp[1][j+1];
        }
        return B;
    }
};