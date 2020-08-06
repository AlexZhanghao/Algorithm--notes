#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n=0,m=0,x=0;
    while(cin>>n>>m>>x){
        priority_queue<int,vector<int>,greater<int>> nums;
        for(int i=0;i<n;++i){
            int a=0;
            cin>>a;
            nums.push(a);
        }

        while(m--){
            int cur=nums.top();
            nums.pop();
            cur+=x;
            nums.push(cur);
        }

        cout<<nums.top()<<endl;
    }
}