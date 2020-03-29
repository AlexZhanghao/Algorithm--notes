#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size()==0) return 0;

        vector<vector<int>> con(2,nums);
        con[0][0]=0;
        for(int i=1;i<nums.size();++i){
            con[0][i]=max(con[0][i-1],con[1][i-1]);
            con[1][i]=con[0][i-1]+nums[i];
        }

        return max(con[0].back(),con[1].back());
    }
};