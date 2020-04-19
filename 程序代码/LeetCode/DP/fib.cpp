#include<iostream>
#include<vector>

#define ll 1000000007;

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int ite1=0,ite2=1,ite;
        int i=1;
        while(i<n){
            ite=(ite1+ite2)%ll;
            ite1=ite2;
            ite2=ite;
            ++i;
        }
        return ite;
    }
};