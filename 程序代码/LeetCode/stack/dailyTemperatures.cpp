#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

//这里使用单调递减栈来处理
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        if(n==0) return {};
        stack<int> s;
        vector<int> out(n,0);
        unordered_map<int,int> pos;
        for(int i=n-1;i>=0;--i){
            pos[T[i]]=i;
            while(!s.empty()&&s.top()<=T[i]) s.pop();
            if(!s.empty()){
                out[i]=pos[s.top()]-i;
            }
            else{
                out[i]=0;
            }
            s.push(T[i]);
        }
        return out;
    }
};