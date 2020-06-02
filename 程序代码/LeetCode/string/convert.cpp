#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n<1||numRows==1) return s;
        vector<string> num(numRows,"");
        int flag=-1,count=0;
        for(int i=0;i<n;++i){
            num[count]+=s[i];
            if(count==0||count==numRows-1) flag=-flag;
            count+=flag;
            
        }
        string out;
        for(int j=0;j<numRows;++j){
            out+=num[j];
        }
        return out;
    }
};