#include<iostream>
#include<vector>

using namespace std;

int main(){
    int *a;
    int *b=a;
    a=new int;
    int *c=a;
    cout<<b<<"   "<<c<<endl;
    
}