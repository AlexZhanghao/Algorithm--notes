#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n){
        string s=to_string(n);
        return Countone(s);
    }

    int Countone(string s){
        int ssize=s.size();
        if(ssize==1){
            if(s=="0") return 0;
            else return 1;
        }
        char high=s[0];
        string last=s;
        last.erase(last.begin());
        while(last.size()>1&&last[0]=='0') last.erase(last.begin());
        string spow="";
        for(int i=0;i<ssize-1;++i) spow+="9";
        int nums_one=0;
        if(high=='1'){
            nums_one=Countone(spow)+atoi(last.c_str())+1+Countone(last);
        }
        else{
            int ipow=1;
            for(int j=0;j<ssize-1;++j) ipow*=10;
            int ihigh=high-48;
            nums_one=Countone(spow)*ihigh+Countone(last)+ipow;
        }
        return nums_one;
    }
};