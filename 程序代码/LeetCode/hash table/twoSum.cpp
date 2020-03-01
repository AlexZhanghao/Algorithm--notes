#include<iostream>
#include<vector>
#include<hash_map>
#include<unordered_map>

using namespace std;

//暴力法
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ts_size=nums.size();
        if(ts_size<2){
            return nums;
        }

        vector<int> twosum;
        int i=0;
        int j=0;
        bool is_find=0;
        while(i<ts_size&&!is_find){
            j=i+1;
            while(j<ts_size){
                if(nums[i]+nums[j]==target){
                    twosum.push_back(i);
                    twosum.push_back(j);
                    is_find=true;
                    break;
                }
                ++j;
            }
            ++i;
        }
        return twosum;
    }
};

//使用哈希表来处理
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        hash_map<int,int> twosum;
        for(int i=0;i<nums.size();++i){
            twosum[nums[i]]=i;
        }

        for(int i=0;i<nums.size();++i){
            if(twosum.find(target-nums[i])!=twosum.end()&&twosum[target-nums[i]]!=i){
                return  {i,twosum[target-nums[i]]};
            }
        }
        return {};
    }
};

int main(){
    vector<int> a={3,2,4};
    vector<int> c;
    Solution2 b;
    c=b.twoSum(a,6);
    for(int i=0;i<c.size();++i){
        cout<<c[i]<<"  ";
    }
    cout<<endl;
}