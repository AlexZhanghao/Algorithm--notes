#include<iostream>

using namespace std;

void InsertSort(int *a,int n){
    for(int i=1;i<n;++i){
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}

int main(){
    int a[10]={9,8,7,6,5,4,1,2,3,10};
    InsertSort(a,10);
    for(int i=0;i<10;++i){
        cout<<a[i]<<" ";
    }
    getchar();
    return 0;
}