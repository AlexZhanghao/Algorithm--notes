#include<iostream>

using namespace std;

int h[100];
int n;

void shiftup(int i){
    int flag=0;
    if(i==0) return;
    while(i!=0&&flag==0){
        if(h[i]<h[i/2]){
            swap(i,i/2);
        }
        else{
            flag=1;
        }
        i=i/2;
    }
    return;
}

void shiftdown(int i){
    int flag=0;
    int t=0;
    while(i*2<n&&flag==0){
        if(h[i]>h[i*2]){
            t=2*i;
        }else{
            t=i;
        }
        if(i*2+1<n){
            if(h[t]>h[i*2+1]){
                t=2*i+1;
            }
        }
        if(t!=i){
            swap(h[t],h[i]);
            i=t;
        }else{
            flag=1;
        }
    }
    return;
}

int deletemin(){
    int t=h[0];
    h[1]=h[n-1];
    --n;
    shiftdown(0);
    return t;
}

void swap(int x,int y){
    int t=h[x];
    h[x]=h[y];
    h[y]=t;
    return;
}

void creat(){
    for(int i=n/2-1;i>=0;--i){
        shiftdown(i);
    }
}