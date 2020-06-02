#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        if(n==0||t.empty()) return "";
        unordered_map<char,int> need,win;
        string out;
        for(char a:t) ++need[a];

        int left=0,right=0,valid=0,start=0,len=INT_MAX;
        while(right<n){
            char c=s[right];
            ++right;
            if(need.count(c)){
                ++win[c];
                if(win[c]==need[c]) ++valid;
            }

            while(valid==need.size()){
                char d=s[left];
                //因为先++right，所以不用再减1了                
                if(len>right-left){
                    start=left;
                    len=right-left;
                }
                ++left;
                if(need.count(d)){
                    --win[d];
                    if(win[d]<need[d]) --valid;
                }
            }
            if(start==left-1){
                out=s.substr(start,len);
            }
        }
        return out;
    }
};