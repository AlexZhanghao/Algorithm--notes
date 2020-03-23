#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int nsize=nums.size();
        int left=0,middle=0,right=nsize-1;
        while(middle<right){
            if(nums[middle]==0){
                Exchange(nums[left],nums[middle]);
                ++left;
                ++middle;
            }
            else if(nums[middle]==2){
                Exchange(nums[middle],nums[right]);
                --right;
            }
            else{
                ++middle;
            }
        }
    }

    void Exchange(int &a,int &b){
        int c=a;
        a=b;
        b=c;
    }
};