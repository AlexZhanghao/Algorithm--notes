#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

//暴力法
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        if(size>num.size()||size<=0) return {};
        int nsize=num.size();
        vector<int> out;
        int maxw=num[0];
        for(int i=1;i<size;++i) maxw=max(maxw,num[i]);
        out.push_back(maxw);
        for(int j=size;j<nsize;++j){
            if(num[j]>=maxw) maxw=num[j];
            else if(num[j]<maxw&&maxw==num[j-size]){
                maxw=num[j];
                for(int k=j-size+1;k<j;++k) maxw=max(maxw,num[k]);
            }
            out.push_back(maxw);
        }
        return out;
    }
};

//单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()||k<=0) return {};
        int nsize=nums.size();
        deque<int> dq;
        dq.push_back(nums[0]);
        for(int i=1;i<k;++i){
            while(!dq.empty()&&dq.back()<nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
        }
        vector<int> out;
        out.push_back(dq.front());
        for(int i=1,j=k;j<nsize;++i,++j){
            if(nums[i-1]==dq.front()) dq.pop_front();
            while(!dq.empty()&&dq.back()<nums[j]) dq.pop_back();
            dq.push_back(nums[j]);
            out.push_back(dq.front());
        }
        return out;
    }
};
//也可以一步到位,但这时dq里面要存位置而不是值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()||k<=0) return {};
        int nsize=nums.size();
        deque<int> dq;
        vector<int> out;
        for(int i=0;i<nsize;++i){
            while(!dq.empty()&&nums[i]>nums[dq.back()]) dq.pop_back();
            //下面这步很关键，这也是为什么要存位置的原因
            if(!dq.empty()&&dq.front()<i-k+1) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1) out.push_back(nums[dq.front()]);
        }
        return out;
    }
};