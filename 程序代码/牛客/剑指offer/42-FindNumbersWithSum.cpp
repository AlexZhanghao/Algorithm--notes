#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int asize=array.size();
        if(asize<2) return{};
        int start=0,end=asize-1,product=INT_MAX;
        vector<int> out(2,0);
        while(start<end){
            int num=array[start]+array[end];
            if(num==sum){
                int pro=array[start]*array[end];
                if(pro<product){
                    product=pro;
                    out[0]=array[start];
                    out[1]=array[end];
                }
                ++start;
                --end;
            }
            else if(num<sum) ++start;
            else --end;
        }

        if(out[0]==0&&out[1]==0) return {};
        return out;
    }
};