#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        if(n==0) return "";
        int l=n-1,r=n-1,len=0;
        string out;
        while(l>=0){
            while(l>=0&&s[l]==' ') --l;
            r=l;
            while(l-1>=0&&s[l-1]!=' ') --l;
            len=r-l+1;
            out+=s.substr(l,len);
            out+=' ';
            --l;
        }
        out.erase(out.end()-1);
        return out;
    }
};