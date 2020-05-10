#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32];
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<32;++j){
                count[j]+=nums[i]&1;
                nums[i]>>=1;//这里要进行无符号右移，暂时还不清楚具体是什么意思
            }
        }
        for(int i=0;i<32;++i){
            count[i]=count[i]%3;
        }
        int res=0;
        for(int j=0;j<32;++j){
            res|=count[31-j];
            res<<=1;
        }
        return res;
    }
};