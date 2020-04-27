#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//这题实际运用了贪心算法，将入栈和出栈给过了一边
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0&&popped.size()==0) return true;
        if(pushed.size()!=popped.size()) return false;
        int pu=0,po=0;
        stack<int> s;
        s.push(pushed[0]);
        for(pu=1;pu<pushed.size();++pu){
            //这里要注意检查s是否为空，防止越界
            while(!s.empty()&&s.top()==popped[po]){
                s.pop();
                ++po;
            }
            s.push(pushed[pu]);
        }
        //pushed = [1,2,3,4,5], popped = [4,5,3,2,1]时，for循环结束后s不为空，但其实是true的
        while(!s.empty()&&s.top()==popped[po]){
            s.pop();
            ++po;
        }
        return s.empty();
    }
};