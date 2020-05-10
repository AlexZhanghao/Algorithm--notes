#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void push(int value) {
        if(minstack.empty()){
            minstack.push_back(value);
            min_num=value;
        }
        else{
            if(value<min_num) min_num=value;
            minstack.push_back(value);
        }
    }
    void pop() {
        if(minstack.empty()) return;
        if(minstack.back()==min_num){
            minstack.pop_back();
            min_num=minstack[0];
            for(int i=1;i<minstack.size();++i){
                if(minstack[i]<min_num) min_num=minstack[i];
            }           
        }else{
            minstack.pop_back();
        }
    }
    int top() {
        if(minstack.empty()) return -1;
        return minstack.back();
    }
    int min() {
        if(minstack.empty()) return -1;
        return min_num;
    }

private:
    vector<int> minstack;
    int min_num;
};