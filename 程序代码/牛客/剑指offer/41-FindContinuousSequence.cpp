#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//这里可以用双指针进行改进
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum==1) return {};
        int mid=(sum/2)+1;
        queue<int> q;
        int i=1,num=0;       
        vector<vector<int>> conseq;
        while(i<=mid){
            num+=i;
            q.push(i);
            if(num>sum){
                while(num>sum){
                    num-=q.front();
                    q.pop();
                }
            }
            if(num==sum){
                vector<int> output;
                for(int j=q.front();j<=i;++j) output.push_back(j);
                conseq.push_back(output);
            }
            ++i;
        }
        return conseq;
    }
};