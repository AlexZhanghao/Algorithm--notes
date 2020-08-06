#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n=0;
    while(cin>>n){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;++i){
            int a=0;
            cin>>a;
            pq.push(a);
        }

        vector<int> nums;
        while(!pq.empty()){
            int cur=pq.top();
            pq.pop();

            if(pq.empty()){
                nums.push_back(cur);
                break;
            }

            if(cur!=pq.top()){
                nums.push_back(cur);
            }
            else{
                cur+=cur;
                pq.pop();
                pq.push(cur);
            }
        }

        for(int i=nums.size()-1;i>=0;--i){
            cout<<nums[i]<<" ";
        }

        cout<<endl;
    }
}