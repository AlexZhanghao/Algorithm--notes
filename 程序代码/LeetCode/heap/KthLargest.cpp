#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// class KthLargest {
// public:
//     KthLargest(int k, vector<int>& nums) {
//         make_heap(nums.begin(),nums.end());
//         K=k;
//         num_copy=nums;
//     }
    
//     int add(int val) {
//         num_copy.push_back(val);
//         push_heap(num_copy.begin(),num_copy.end());
//         sort_heap(num_copy.begin(),num_copy.end());
//         int n=num_copy.size();
//         return num_copy[n-K+1];
//     }

// private:
//     int K;
//     vector<int> num_copy;
// };

class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }       
        K = k;
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K) pq.pop();
        return pq.top();
    }
};
