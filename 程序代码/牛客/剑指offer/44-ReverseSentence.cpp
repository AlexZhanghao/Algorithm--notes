#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string a,out;
        int ssize=str.size();
        int i=0;
        while(i<ssize){
            if(str[i]==' '){
                a=' '+a;
                out=a+out;
                a="";
                ++i;
            }
            else{
                a+=str[i];
                ++i;
            }
        }
        return out;
    }
};

//双指针法,力扣解答
class Solution {
public:
    string reverseWords(string s) {
        int ssize=s.size();
        if(ssize==0) return s;
        int len=0;
        string out;
        for(int i=ssize-1;i>=0;--i){
            if(s[i]==' '&&len!=0){
                out+=s.substr(i+1,len)+' ';
                len=0;
                continue;
            }

            if(s[i]!=' ') ++len;
        }
        if(len!=0) out+=s.substr(0,len);
        else if(out.size()>0) out.erase(out.size()-1,1);
        return out;
    }
};