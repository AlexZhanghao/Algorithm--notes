#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

#define M 1000000007

//最小栈
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n=A.size();
        if(n==0) return 0;
        stack<int> s;
        vector<int> sums(n,0);
        for(int i=0;i<n;++i){
            while(!s.empty()&&A[s.top()]>=A[i]) s.pop();
            if(s.empty()){
                //i是从0开始的，所以这里要乘以i+1
                sums[i]=A[i]*(i+1);
            }
            else{
                sums[i]=sums[s.top()]+A[i]*(i-s.top());
            }
            //因为不能保证当前的A[i]一定比后面的数大，所以这里必须把它放入栈中
            s.push(i);
            sums[i]%=M;
        }
        long res=0;
        for(auto a:sums){
            res+=a;
            res%=M;
        }
        return res;
    }
};