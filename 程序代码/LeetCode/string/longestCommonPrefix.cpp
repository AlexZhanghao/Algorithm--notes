#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n<1) return "";
        int i=0,count=0;
        string out="";
        while(true){
            ++count;
            //防止strs[0]==""，或者可以在开头直接判断它是不是等于""
            if(strs[0].size()<=i) return out;
            char a=strs[0][i];
            for(int j=1;j<n;++j){
                //这里的strs[j].size()<count要根据++count的位置来定是使用"<"还是"<="
                if(strs[j].size()<count||strs[j][i]!=a) return out;
            }
            ++i;
            out+=a;
        }
        return out;
    }
};