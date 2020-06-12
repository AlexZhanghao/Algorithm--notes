#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int n1=nums1.size();
        if(n==0||n1==0) return {};
        unordered_map<int,int> um;
        stack<int> s;
        for(int i=n-1;i>=0;--i){
            while(!s.empty()&&nums2[i]>=s.top()) s.pop();
            if(s.empty()){
                um[nums2[i]]=-1;
            }
            else{
                um[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        
        vector<int> out;
        for(int j=0;j<n1;++j){
            out.push_back(um[nums1[j]]);
        }
        return out;
    }
};