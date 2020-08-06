#include<iostream>

using namespace std;


int main(){
    char greeting[]="hello";
    char g2[]="Hello";

    const char* p1=greeting;

    char* const p2=greeting;

    const char* const p3=greeting;

    p1=g2;
    while(*p1!='\0'){
        cout<<*p1;
        ++p1;
        
    }
    cout<<endl;
    
    *p2='H';
    char *p4=p2;
    while(*p4!='\0'){
        cout<<*p4;
        ++p4;     
    }
    cout<<endl;

    return 0;
}