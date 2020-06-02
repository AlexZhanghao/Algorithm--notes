#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;        
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(nums[mid]<nums[r]){
                if(target>=nums[mid]&&target<=nums[r]){
                    l=mid;
                }
                else{
                    r=mid-1;
                }
            }
            else {
                if(target>=nums[l]&&target<=nums[mid-1]){
                    r=mid-1;
                }
                else{
                    l=mid;
                }
            }
        }
        if(nums[l]==target) return l;
        return -1;
    }
};