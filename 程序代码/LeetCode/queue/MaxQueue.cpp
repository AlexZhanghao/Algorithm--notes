#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class MaxQueue {
public:
    queue<int> a;
    deque<int> b;

public:
    MaxQueue() {

    }
    
    int max_value() {
        if(a.empty()){
            return -1;
        }
        return b.front();
    }
    
    void push_back(int value) {
        while(!b.empty()&&value>b.back()){
            b.pop_back();
        }
        b.push_back(value);
        a.push(value);
    }
    
    int pop_front() {
        if(a.empty()){
            return -1;
        }
        int cnt=a.front();
        if(!b.empty()&&cnt==b.front()){
            b.pop_front();
        }
        a.pop();
        return cnt;       
    }
};