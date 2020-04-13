#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1) return 0;
        vector<int> a(n+1,0);
        a[n]=1;
        a[n-1]=1;
        for(int i=2;i<n+1;++i){
            a[n-i]=a[n-i+1]+a[n-i+2];
        }
        return a[0];
    }
};