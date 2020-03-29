#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int nsize=nums.size();
        unordered_set<int> con(nums.begin(),nums.end());
        //下面这种写法在力扣上无法通过
        // for(auto i:nums){
        //     con.insert(nums[i]);
        // }

        int ls=0;
        for(auto j:con){
            if(con.count(j-1)) continue;
            int k=1;
            while(con.count(j+1)){
                ++k;
                ++j;
            }
            ls=max(ls,k);
        }

        return ls;
    }
};