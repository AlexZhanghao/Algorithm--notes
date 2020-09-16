#include<iostream>
#include<vector>

using namespace std;

int main(){
    int b=10;
    const int a=b;
    cout<<a<<endl;
    int *c=(int*)&a;
    *c=20;
    cout<<a<<endl;
    return 0;
}