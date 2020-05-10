#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n=-2147483648;
    n=-n;
    unsigned y=~n;
    y=y+1;
    cout<<y<<endl;
}