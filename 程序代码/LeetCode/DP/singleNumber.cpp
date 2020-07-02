#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int ret=0;
        
        for(int i=0;i<32;++i){
            int bit=1<<i;
            int count=0;
            for(int a:nums){
                if(a&bit) ++count;
            }
            if(count%3){
                ret|=bit;
            }
        }

        return ret;
    }
};