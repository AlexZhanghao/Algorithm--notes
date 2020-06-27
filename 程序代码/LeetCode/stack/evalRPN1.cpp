#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> s;
        for(int i=0;i<n;++i){
            if(tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/"){
                s.push(atoi(tokens[i].c_str()));
            }
            else{
                int s1=s.top();
                s.pop();
                int s2=s.top();
                s.pop();
                switch (tokens[i][0])
                {
                case '+':
                    s.push(s1+s2);
                    break;

                case '-':
                    s.push(s2-s1);
                    break;

                case '*':
                    s.push(s1*s2);
                    break;

                case '/':
                    s.push(s2/s1);
                    break;

                default:
                    break;
                }
            }
        }

        return s.top();
    }
};