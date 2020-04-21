#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int nsize=nums.size();
        int start=0,end=nsize-1;
        while(start<end){
            //这里要防止越界的情况发生
            while(nums[start]%2==1&&start<nsize-1) ++start;
            while(nums[end]%2==0&&end>0) --end;
            //交换前要检查,这点很重要!!!
            if(start<end) Exchange(nums[start],nums[end]);           
            ++start;
            --end;
        }

        return nums;
    }

private:
    void Exchange(int &a,int &b){
        int c=a;
        a=b;
        b=c;
        return;
    }
};