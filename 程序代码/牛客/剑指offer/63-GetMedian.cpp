#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//排序
class Solution {
public:
    void Insert(int num){
        nums.push_back(num);
        sort(nums.begin(),nums.end());
    }

    double GetMedian(){ 
        int nsize=nums.size();
        if(nsize<1) return 0;
        if(nsize%2==1) return nums[nsize/2];
        else return (nums[nsize/2]+nums[(nsize/2)-1])/2;
    }

private:
    vector<double> nums;
};


//优先队列
class Solution {
public:
    void Insert(int num){
        if(left.empty()||num<=left.top()) left.push(num);
        else right.push(num);
        if(left.size()==right.size()+2){
            right.push(left.top());
            left.pop();
        }
        if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }

    double GetMedian(){
        if((left.size()+right.size())%2==1) return left.top();
        else{
            return (left.top()+right.top())/2.0;
        }
    }

private:
    //默认是max-heap，即每个节点的键值大于等于子节点的键值，相当于priority_queue<int,vector<int>, less<int>> 
    priority_queue<int> left;
    //与上面的相反
    priority_queue<int,vector<int>, greater<int>> right;
};