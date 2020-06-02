#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        if(n<1) return {};
        vector<vector<string>> out;
        //string用以存sort后的str，而int存它在out中的位置
        unordered_map<string,int> m;
        int count=0;
        string tem;
        for(auto str:strs){
            tem=str;
            sort(str.begin(),str.end());
            if(m.count(str)){
                out[m[str]].push_back(tem);
            }
            else{               
                m[str]=count;
                out.push_back({tem});
                ++count;
            }
        }
        return out;
    }
};