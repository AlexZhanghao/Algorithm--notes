#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//失败！！！
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int ssize=seq.size();
        if(ssize==0) return {};
        vector<int> maxdep(ssize,0);
        vector<int> book(ssize,0);
        stack<char> s;
        for(int i=0;i<ssize;++i){
            if(seq[i]=='('){
                s.push(seq[i]);
                if(i=0) {
                    book[i]==1;
                }
                else{
                    if(seq[i-1]=='('){
                        book[i]=book[i-1]+1;
                    }
                    else{
                        book[i]=book[i-1];
                    }                   
                }
            }
            else{
            }
        }
    }
};

//这里d用来记录当前堆的高度
class Solution2 {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};
