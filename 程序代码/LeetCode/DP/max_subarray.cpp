#include<iostream>
#include<string>
#include<vector>
#include <Windows.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_num=nums[0];

        for(int i=1;i<n;++i){
            if(nums[i-1]>0){
                nums[i]+=nums[i-1];
            }
            max_num=max(max_num,nums[i]);
        }
        return max_num;
    }
};