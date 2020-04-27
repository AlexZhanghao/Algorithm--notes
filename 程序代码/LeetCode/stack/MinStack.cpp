#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_num=0;
    }
    
    void push(int x) {
        if(stack_nums.empty()){
            stack_nums.push_back(x);
            min_num=x;
        }
        else{
            stack_nums.push_back(x);
            if(x<min_num) min_num=x;
        }
    }
    
    void pop() {
        if(top()==min_num){
            stack_nums.pop_back();
            min_num=*min_element(stack_nums.begin(),stack_nums.end());
        }
        else{
            stack_nums.pop_back();
        }
    }
    
    int top() {
        return stack_nums.back();
    }
    
    int getMin() {
        return min_num;
    }

private:
    int min_num;
    vector<int> stack_nums;
};