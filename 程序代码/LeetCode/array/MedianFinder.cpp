#include<iostream>
#include<queue>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        size=0;
    }
    
    void addNum(int num) {
        if(big.empty()) big.push(num);
        else if(size%2){
            if(num>big.top()){
                small.push(big.top());
                big.pop();
                big.push(num);
            }
            else small.push(num);
        }
        else{
            if(!small.empty()&&num<small.top()){
                big.push(small.top());
                small.pop();
                small.push(num);
            }
            else big.push(num);
        }
        ++size;
    }
    
    double findMedian() {
        if(size%2) return big.top();
        else return (big.top()+small.top())/2;
    }

private:
    priority_queue<double,vector<double>,greater<double>> big;
    priority_queue<double,vector<double>,less<double>> small;
    int size;
};