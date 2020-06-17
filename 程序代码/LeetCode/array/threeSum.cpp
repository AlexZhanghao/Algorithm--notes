#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> out;
        int start=0,left=0,right=0;
        for(;start<n-2;++start){
            left=start+1;
            right=n-1;
            while(left<right){
                //下面两个查重只需要留一个，这里好好品味下缘由
                if(left>start+1&&nums[left]==nums[left-1]){
                    ++left;
                    continue;
                }
                // if(right<n-1&&nums[right]==nums[right+1]){
                //     --right;
                //     continue;
                // }

                int sum=nums[start]+nums[left]+nums[right];
                if(sum>0) --right;
                else if(sum<0) ++left;
                else{
                    vector<int> a={nums[start],nums[left],nums[right]};
                    out.push_back(a);
                }
            }
        }
        return out;
    }
};