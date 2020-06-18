#include<iostream>

using namespace std;

void BubbuleSort(int *a,int n){
    for(int i=0;i<n-1;++i){
        for(int j=0;j<n-i-1;++j){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

int main(){
    int a[10]={9,8,7,6,5,4,1,2,3,10};
    BubbuleSort(a,10);
    for(int i=0;i<10;++i){
        cout<<a[i]<<" ";
    }
    getchar();
    return 0;
}