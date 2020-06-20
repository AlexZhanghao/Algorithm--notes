#include<iostream>

using namespace std;

char *My_strcpy(char *dest,const char* str){
    if(dest==nullptr||str==nullptr) return nullptr;
    char* cp=dest;
    while((*cp++=*str++)!='\0'){};

    return dest;
}

char *My_strncpy(char* dest,const char* str,int n){
    if(dest==nullptr||str==nullptr) return nullptr;
    char *cp=dest;

    while(n&&(*cp++=*str++)!='\0'){
        --n;
    }

    //当n>=sizeof(src)时，拷贝正确，并在dest字符串后面加入'\0';
    //当n<sizeof(src)时，只拷贝src前n-1个字符串到dest，不会为dest字符串后面加入'\0';
    if(n){
        //因为若此时n还大于0，说明str以及一个'\0'已经拷贝到dest中，而这个'\0'在上面并没有计算进n中，所以这里先--n
        while(--n){
            *cp++='\0';
        }
    }

    return dest;
}