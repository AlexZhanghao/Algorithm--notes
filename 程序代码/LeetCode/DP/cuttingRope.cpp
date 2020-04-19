#include<iostream>
#include<vector>

using namespace std;

//这里结合了乘3的特性以及DP
class Solution {
public:
    int cuttingRope(int n) {
        vector<long> dp(1001,0);
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=4;
        dp[5]=6;
        dp[6]=9;
        for(int i=7;i<=n;i++){
            dp[i]=(dp[i-3]*3)%1000000007;
        }
        return dp[n];
    }
};

//这个是integerBreak的大数版本，主要就是要把求余处理好
typedef  long long ll;

class Solution2 {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int a=n/3-1;
        int b=n%3;
        ll max_ib=1;
        ll p=3;
        int bigre=1000000007;
        while(a>0){
            if(a%2==1){
                max_ib=max_ib*p%bigre;
                --a;
            } 
            else {
                p=p*p%bigre;
                a=a/2;
            }
            
        }
        switch (b)
        {
        case 0:
            max_ib=max_ib*3%bigre;
            break;
        case 1:
            max_ib=max_ib*4%bigre;
            break;
        case 2:
            max_ib=max_ib*6%bigre;
            break;
        }
        return max_ib;
    }
};