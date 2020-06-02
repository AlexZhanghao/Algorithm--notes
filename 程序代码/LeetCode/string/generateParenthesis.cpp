#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//dfs
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n<1) return {};
        int left=n,right=n;
        vector<string> out;
        string s;
        dfs(out,s,left,right);
        return out;
    }

    void dfs(vector<string> &out,string s,int left,int right){
        if(left>right) return;
        if(right==0){
            out.push_back(s);
            return;
        }
        else if(left==0){
            string s1=s;
            while(right>0){
                s1+=')';
                --right;
            }
            out.push_back(s1);
            return;
        }
        else{
            string s1,s2;
            s1=s+')';
            dfs(out,s1,left,right-1);
            s2=s+'(';
            dfs(out,s2,left-1,right);
        }
    }
};