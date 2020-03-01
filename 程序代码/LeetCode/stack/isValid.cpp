#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int ssize= s.size();

        if(ssize==0){
            return true;
        }
        //这里的处理值得学习
        else if(ssize%2){
            return false;
        }

        const char left1='(';
        const char left2='[';
        const char left3='{';
        const char right1=')';
        const char right2=']';
        const char right3='}';

        if(s[0]==right1||s[0]==right2||s[0]==right3){
            return false;
        }

        stack<char> a;
        for(int i=0;i<ssize;++i){
            if(s[i]==left1||s[i]==left2||s[i]==left3){
                a.push(s[i]);
            }
            else{
                if(s[i]==right1&&a.top()!=left1||s[i]==right2&&a.top()!=left2||s[i]==right3&&a.top()!=left3){
                    return false;
                }else{
                    a.pop();
                }
            }
        }

        return a.empty();
    }
};