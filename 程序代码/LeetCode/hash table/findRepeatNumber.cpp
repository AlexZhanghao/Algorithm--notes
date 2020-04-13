#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int nsize=nums.size();
        if(nsize<2) return 0;
        unordered_map<int,int> um;
        for(int i=0;i<nsize;++i){
            ++um[nums[i]];
        }
        for(auto ite=um.begin();ite!=um.end();++ite){
            if(ite->second>1) return ite->first;
        }
        return 0;
    }
};

//这个思路很好，他是一边比对一边排序，让nums[i]在nums[nums[i]]的位置上，如果再遇到就直接返回
class Solution2 {
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp;
        for(int i=0;i<nums.size();i++){
            while (nums[i]!=i){
                if(nums[i]==nums[nums[i]]){
                    return nums[i];
                }
                temp=nums[i];
                nums[i]=nums[temp];
                nums[temp]=temp;
            }
        }
        return -1;
    }
}；