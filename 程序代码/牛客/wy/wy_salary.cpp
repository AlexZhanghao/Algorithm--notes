#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int m,n;
    cin>>n;
    cin>>m;

    unordered_map<int,int> salary;
    for(int i=0;i<n;++i){
        int k;
        cin>>k;
        ++salary[k];
    }

    for(int j=0;j<m;++j){
        int p=0;
        cin>>p;
        printf("%d\n",salary[p]);
    }

    return 0;
}