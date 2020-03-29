#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> dm;
        vector<int> sx;
        for(int i=0;i<deck.size();++i){
            ++dm[deck[i]];
        }

        for(auto j:dm){
            sx.push_back(j.second);
        }
        sort(sx.begin(),sx.end());
        for(int k=1;k<dm.size();++k){
            if(dm[k]%dm[0]!=0) return false;
        }
        return true;
    }
};