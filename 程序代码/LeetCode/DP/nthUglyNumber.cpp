#include <iostream>
#include <vector>
#include<queue>
#include<unordered_set>
#include <algorithm>

using namespace std;

//三指针的DP
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<1) return 0;
        int* dp=new int[n];
        dp[0]=1;
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;++i){
            int num=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(num==dp[p2]*2) ++p2;
            if(num==dp[p3]*3) ++p3;
            if(num==dp[p5]*5) ++p5;
            dp[i]=num;
        }
        int out=dp[n-1];
        delete []dp;
        return out;
    }
};

//优先队列
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        unordered_set<int> s;
        s.insert(1);
        vector<int> mask({2,3,5});
        double answer=1;
        for (int i=1;i<n;++i)
        {
            for (int &j:mask){
                if (s.count(answer*j)==0)
                {
                    q.push(answer*j);
                    s.insert(answer*j);
                }
            }
            answer=q.top();
            q.pop();
        }
        return answer;
    }
};