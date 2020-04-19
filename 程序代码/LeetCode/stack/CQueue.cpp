#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class CQueue {
public:
    //注意这里哦！因为要求初始为空，这里要是初始为0后面就尴尬了
    CQueue() {
    }
    
    //插入元素时直接将元素置于head的栈首
    void appendTail(int value) {
        head.push(value);
    }
    
    //删除时分三种情况：tail还有值，tail没head有，都没了
    int deleteHead() {
        int a=-1;
        if(!tail.empty()){
            a=tail.top();
            tail.pop();
        }
        else if(!head.empty()){
            while(!head.empty()){
                tail.push(head.top());
                head.pop();
            }
            a=tail.top();
            tail.pop();
        }
        return a;
    }

private:
    stack<int> head;
    stack<int> tail;
};
