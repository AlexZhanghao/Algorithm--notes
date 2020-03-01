#include<iostream>
#include<vector>

using namespace std;

//双指针法，虽然简单，但很有味道
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        
        int i=0;
        int j=1;
        for(;j<nums.size();++j){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                ++i;
            }
        }
        return i+1;
    } 
};