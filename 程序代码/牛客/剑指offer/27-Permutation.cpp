#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str=="") return {};
        dfs(str,0);
        return output;
    }

    void dfs(string str,int cur){
        if(cur==str.size()-1){
            output.push_back(str);
            return;
        }
        unordered_set<char> s;
        for(int i=cur;i<str.size();++i){
            if(s.count(str[i])) continue;
            s.insert(str[i]);
            swap(str[i],str[cur]);
            dfs(str,cur+1);
        }
    }

private:
    vector<string> output;
};