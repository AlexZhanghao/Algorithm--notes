#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> nums3;
        int left=0,right=0;
        while(left<n1&&right<n2){
            if(nums1[left]<nums2[right]){
                nums3.push_back(nums1[left]);
                ++left;
            }
            else if(nums1[left]>nums2[right]){
                nums3.push_back(nums2[right]);
                ++right;
            }
            else{
                nums3.push_back(nums1[left]);
                nums3.push_back(nums2[right]);
                ++left;++right;
            }
        }

        if(left!=n1){
            while(left<n1){
                nums3.push_back(nums1[left]);
                ++left;
            }
        }
        if(right!=n2){
            while(right<n2){
                nums3.push_back(nums2[right]);
                ++right;
            }
        }

        int n=nums3.size();
        double ret=0;
        if(n%2) ret=nums3[(n-1)/2];
        else{
            ret=nums3[(n)/2]+nums3[(n-1)/2];
            ret/=2;
        }
        return ret;
    }
};

//二分法时间优化
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=(n1+n2)/2;
        int half=n/2;
        int l1=0,l2=0,count=0;
        while(count<n){
            int h1=0,h2=0;
            if(half>=n1){
                
            }
        }
    }
};