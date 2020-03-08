#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m=-2;
    int *n=&m;
    m=0;
    cout<<*n<<endl;
}