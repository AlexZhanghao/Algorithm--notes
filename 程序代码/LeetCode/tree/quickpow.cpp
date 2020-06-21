#include<iostream>

using namespace std;

int QuickPow(int i,int n){
    int out=1;
    while(n>0){
        if(n%2==1){
            out*=i;
            --n;
        }
        else{
            i*=i;
            n=n/2;
        }
    }
    return out;
}