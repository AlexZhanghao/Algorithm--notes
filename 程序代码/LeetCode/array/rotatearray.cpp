#include<iostream>
#include<vector>

using namespace std;

//法一：不断和前k位替换，未通过！！！
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||k==0) return;
        k=k%n;
        int i=n-k;
        int pos=k;
        while(i>0){
            for(int j=0;j<k;++j){
                swap(nums[j],nums[(pos+j)%n]);
                --i;
            }
            pos+=k;
        }
    }
};

//法二：三次翻转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||k==0) return;
        k=k%n;
        reversal(nums,0,n-1);
        reversal(nums,0,k-1);
        reversal(nums,k,n-1);
    }

    void reversal(vector<int> &nums,int left,int right){
        while(left<right){
            swap(nums[left],nums[right]);
            ++left;
            --right;
        }
    }
};