#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int left=0,right=data.size()-1,mid=0,count=0;
        while(left<=right){
            mid=(left+right)/2;
            if(data[mid]>k) right=mid-1;              
            else if(data[mid]<k) left=mid+1;
            else break;
        }
        if(data[mid]==k){
            count=1;
            int mid_l=mid-1,mid_r=mid+1;
            while(mid_l>=0&&data[mid_l]==k){
                ++count;
                --mid_l;
            }
            while(mid_r<=data.size()-1&&data[mid_r]==k){
                ++count;
                ++mid_r;
            }
        }

        return count;
    }
};