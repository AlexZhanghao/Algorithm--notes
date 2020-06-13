#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n==0) return true;
        //这个解法中这一步是很有必要的，否则遇到"[])"时，下面sc.top()会报错
        if(n%2==1) return false;

        const char left1='(';
        const char left2='[';
        const char left3='{';
        const char right1=')';
        const char right2=']';
        const char right3='}';

        if(s[0]==right1||s[0]==right2||s[0]==right3)  return false;

        stack<char> sc;

        for(int i=0;i<n;++i){
            if(s[i]==left1||s[i]==left2||s[i]==left3) sc.push(s[i]);
            else if(s[i]==right1&&sc.top()!=left1||s[i]==right2&&sc.top()!=left2||s[i]==right3&&sc.top()!=left3) return false;
            else sc.pop();;
        }

        return sc.empty();
    }
};