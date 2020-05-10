#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string a;
        int ssize=str.size();
        if(ssize==0) return a;
        n=n%ssize;
        for(int j=n;j<ssize;++j) a+=str[j];
        for(int i=0;i<n;++i) a+=str[i];
        return a;
    }
};