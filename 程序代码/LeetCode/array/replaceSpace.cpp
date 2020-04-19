#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string out;
        char a='%';
        char b='2';
        char c='0';
        for(int i=0;i<s.size();++i){
            if(s[i]==' '){               
                out.push_back(a);
                out.push_back(b);
                out.push_back(c);
            }else{
                out.push_back(s[i]);
            }
        }
        return out;
    }
};