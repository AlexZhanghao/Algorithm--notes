#include<iostream>

using namespace std;

void stacktest(int a,int b){
    cout<<&a<<endl;
    cout<<&b<<endl;
}

int main(){
    stacktest(1,2);
    return 0;
}