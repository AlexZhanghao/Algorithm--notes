#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10) return {};
        unordered_set<string> book,readyset;
        vector<string> out;
        for(int i=0;i<n-9;++i){
            string ss=s.substr(i,10);
            if(book.count(ss)&&!readyset.count(ss)){
                out.push_back(ss);
                readyset.insert(ss);
            } 
            else {
                book.insert(ss);              
            }
        }
        return out;
    }
};