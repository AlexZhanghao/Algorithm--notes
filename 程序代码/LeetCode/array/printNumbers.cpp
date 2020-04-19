#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//快速幂
class Solution {
public:
    vector<int> printNumbers(int n) {
        int cnt=1;
        int p=10;
        while(n>0){
            if(n%2==1){
                cnt=cnt*p;
                --n;
            }
            else{
                p=p*p;
                n=n/2;
            }
        }
        --cnt;
        vector<int> v;
        for(int i=0;i<cnt;++i) v.push_back(i+1);
        return v;
    }
};

//自带算法，速度上相比快速幂实现要慢一点
class Solution {
   public:
    vector<int> printNumbers(int n) {
     int num=pow(10,n)-1;
     vector<int> v;
     for(int i=0;i<num;i++){
         v.push_back(i+1);
     }
     return v;
   }
};
