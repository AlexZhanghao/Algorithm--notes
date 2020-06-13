#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//II相比I增设了循环数组的条件，这里的处理方式是，在原数组的后面接上一个原数组，使其翻倍。
//这里有个技巧，我们可以并不将它真的翻倍，而是运用%来进行模拟
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        vector<int> out(n,0);
        stack<int> s;
        for(int i=2*n-1;i>=0;--i){
            while(!s.empty()&&nums[i%n]>=s.top()) s.pop();
            out[i%n]=(s.empty())?-1:s.top();
            s.push(nums[i%n]);
        }
        return out;
    }
};