#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//DP法
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<n+1;++i){
            for(int j=1;j<i;++j){
                int d=max(j*(i-j),j*dp[i-j]);
                if(d>dp[i]) dp[i]=d;
            }
        }

        return dp[n];
    }
};

//贪心算法
//根据https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/
//这位小哥的数学上的分析，n在分割时应当以3优先
class Solution2 {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int a=n/3;
        int b=n%3;
        int max_ib=0;
        switch (b)
        {
        case 0:
            max_ib=QuickPow(a);
            break;
        case 1:
            max_ib=QuickPow(a-1)*4;
            break;
        case 2:
            max_ib=QuickPow(a)*2;
            break;
        default:
            break;
        }
        return max_ib;
    }

private:
    //快速幂
    int QuickPow(int a){
        int qp=1;
        int cnt=3;
        while(a>0){
            if(a%2==0){
                a=a/2;
                cnt=cnt*cnt;
            }
            else{
                --a;
                qp=qp*cnt;
            }
        }
        return qp;
    }
};