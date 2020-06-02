#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n=s.size();
        if(n<1) return false;
        unordered_map<char,int> m;
        for(int i=0;i<n;++i){
            ++m[i];
        }
        int count=0;
        for(auto ptr=m.begin();ptr!=m.end();++ptr){
            int i=ptr->second;
            if(i/2==1){
                if(count==1) return false;
                else ++count;
            }
        }
        return true;
    }
};