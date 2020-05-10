#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n=resxor(data);
        int div=Findfirstbit1(n);
        vector<int> a,b;
        for(int i:data){
            if(i&div) a.push_back(i);
            else b.push_back(i);
        }
        
        *num1=resxor(a);
        *num2=resxor(b);
    }

    int resxor(vector<int> data){
        int out=data[0];
        for(int i=1;i<data.size();++i){
            out^=data[i];
        }
        return out;
    }

    int Findfirstbit1(int n){
        int div = 1;
        while ((div & n) == 0)
            div <<= 1;
        return div;
    }
};