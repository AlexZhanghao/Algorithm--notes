#include<iostream>

using namespace std;

double QuickPow(double x,int n){
    double q=1;
    while(n>0){
        if(n%2){
            q*=x;
            --n;
        }
        else{
            x*=x;
            n/=2;
        }
    }
    return q;
}

int main(){
    cout<<QuickPow(2,100)<<endl;
    return 0;
}