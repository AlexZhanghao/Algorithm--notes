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
        int start=0,left,right;
        vector<vector<int>> out;
        vector<int> v;
        while(start<n-2&&nums[start]<=0){
            if(start>0&&nums[start]==nums[start-1]){
                ++start;
                continue;
            }            
            left=start+1;
            right=n-1;
            while(left<right){
                if(left>start+1&&nums[left]==nums[left-1]){
                    ++left;
                    continue;
                }
                if(nums[start]+nums[left]+nums[right]==0){
                    v.push_back(nums[start]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    out.push_back(v);
                    v.clear();
                    ++left;--right;
                }
                else if(nums[start]+nums[left]+nums[right]>0) --right;
                else ++left;
            }
            ++start;
        }
        return out;
    }
};