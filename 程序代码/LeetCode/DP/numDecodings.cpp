#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0') return 0;
        int ssize=s.size();
        if(ssize==1) return 1;
        int per=1,dper=1,curr=1;
        
        for(int i=1;i<s.size();++i){
            //情况1
            if(s[i]=='0'&&s[i-1]!='1'&&s[i-1]!='2'){
                return 0;
            }
            else if(s[i]=='0'&&(s[i-1]=='1'||s[i-1]=='2')){
                curr=dper;
                dper=per;
                per=curr;
            }
            //情况2
            else if(s[i-1]=='1'){
                curr=per+dper;
                dper=per;
                per=curr;
            }
            //情况3
            else if(s[i-1]=='2'&&s[i]>'0'&&s[i]<'7'){
                curr=per+dper;
                dper=per;
                per=curr;
            }
            //剩余情况
            else{
                curr=per;
                dper=per;
            }
        }

        return curr;
    }
};