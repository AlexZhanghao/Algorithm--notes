#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> a,b;
        for(int i=0;i<n;++i){
            int a1;
            cin>>a1;
            a.push_back(a1);
        }
        for(int j=0;j<n;++j){
            int b1;
            cin>>b1;
            b.push_back(b1);
        }
    }
}