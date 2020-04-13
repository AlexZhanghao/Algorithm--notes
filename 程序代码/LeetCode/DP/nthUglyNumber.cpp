#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>

using namespace std;

//超时...
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        unordered_set<int> dp;
        dp.insert(1);
        int count=1;
        int i=1;
        while(count<n){
            ++i;
            if((i%2==0&&dp.find(i/2)!=dp.end())||(i%3==0&&dp.find(i/3)!=dp.end())||(i%5==0&&dp.find(i/5)!=dp.end())){
                ++count;
                dp.insert(i);
            }            
        }
        return i;
    }
};

//官解的三指针版动态规划
class Solution2 {
public:
    int nthUglyNumber(int n) {
        int ite1=1,ite2=1,ite3=1;
        int count[1691];
        count[1]=1;
        for(int i=2;i<n+1;++i){
            int minnum=min(min(count[ite1]*2,count[ite2]*3),count[ite3]*5);
            count[i]=minnum;
            if(minnum==count[ite1]*2){                
                ++ite1;
            }
            if(minnum==count[ite2]*3){
                ++ite2;
            }
            if(minnum==count[ite3]*5){
                ++ite3;
            }
        }

        return count[n];
    }
};