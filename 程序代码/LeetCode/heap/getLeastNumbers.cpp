#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k==0) return {};
        priority_queue<int> Q;
        for(int i=0;i<k;++i){
            Q.push(arr[i]);
        }

        for(int i=k;i<arr.size();++i){
            if(arr[i]<Q.top()){
                Q.pop();
                Q.push(arr[i]);
            }
        }

        vector<int> leastnums;
        for(int i=0;i<k;++i){
            leastnums.push_back(Q.top());
            Q.pop();
        }

        return leastnums;
    }
};