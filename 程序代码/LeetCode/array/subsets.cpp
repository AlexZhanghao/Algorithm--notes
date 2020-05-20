#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//运用DP自底向上的思想
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        vector<vector<int>> out;
        out.push_back({});
        for(int i=0;i<n;++i){
            int osize=out.size();
            for(int j=0;j<osize;++j){
                vector<int> mid=out[j];
                mid.push_back(nums[i]);
                out.push_back(mid);
            }
        }
        return out;
    }
};