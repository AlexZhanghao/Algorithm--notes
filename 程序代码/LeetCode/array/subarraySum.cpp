#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<1) return 0;
        int l=0,count=0;
        while(l<n){
            int sum=0;
            int r=l;
            while(r<n){
                sum+=nums[r];
                if(sum==k) ++count;;
                ++r;
            }
            //如当遇到{0,0,0}和0的组合时应该输出6而不是3
            //if(sum==k) ++count;
            ++l;
        }
        return count;
    }
};