#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       int nums1size=nums1.size();        
       int nums2size=nums2.size();
       vector<int> target;
       set<int>::iterator ite;
       set<int>::iterator send;
       set<int>::iterator ite1;
       set<int>::iterator ite2;

       set<int>snums1;
       set<int>snums2;

       snums1.insert(nums1.begin(),nums1.end());
       snums2.insert(nums2.begin(),nums2.end());

       if(nums1size>nums2size){
           ite=snums2.begin();
           send=snums2.end();
           for(;ite!=send;++ite){
               ite1=find(snums1.begin(),snums1.end(),*ite);
               if(ite1!=snums1.end()){
                   target.push_back(*ite);
               }
           }
       }
       else{
           ite=snums1.begin();
           send=snums1.end();
           for(;ite!=send;++ite){
               ite1=find(snums2.begin(),snums2.end(),*ite);
               if(ite1!=snums2.end()){
                   target.push_back(*ite);
               }
           }
       }
       
       return target;
    }
};

int main(){
    vector<int> nums1={1,2,2,1};
    vector<int> nums2={2,2};

    Solution s;
    s.intersection(nums1,nums2);
}