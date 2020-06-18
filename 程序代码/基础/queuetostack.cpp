#include<iostream>
#include<queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        top_num=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        top_num=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()) return -1;
        int out=0;
        if(q1.size()==1){
            out=q1.front();
            q1.pop();
            return out;
        }

        while(q1.size()>2){
            q2.push(q1.front());
            q1.pop();
        }

        int a=q1.front();
        q1.pop();
        out=q1.front();
        q1.pop();       
               
        if(!q2.empty()){
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        q1.push(a);
        top_num=a;
        return out;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty()) return false;
        return top_num;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }

private:
    int top_num;
    queue<int> q1,q2;
};