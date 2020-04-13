#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> start,end;
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        start.push_back(j);
    }
    for(int i=0;i<n;++i){
        int j;
        cin>>j;
        end.push_back(j);
    }

    unordered_map<int,int> um;
    int cnt=0;
    for(int i=0;i<n;++i){
        um[end[i]]=i;
    }
    for(int j=0;j<n;++j){
        if(um[start[j]]<j) ++cnt;
    }

    printf("%d\n",cnt);
    return 0;
}