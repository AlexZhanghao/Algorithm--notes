#include<iostream>

using namespace std;

//memcpy和memmove（）都是C语言中的库函数，在头文件string.h中，作用是从src内存中拷贝n个字节到dst内存区域。
//他们的区别是，当内存发生局部重叠的时候，memmove保证拷贝的结果是正确的，memcpy不保证拷贝的结果的正确。
void *my_memcpy(void *dst,const void* src,size_t n){
    char *tmp=(char*)dst;
    char *s_src=(char*)src;

    while(n){
        *tmp=*s_src;
        ++tmp;
        ++s_src;
        --n;
    }
    return dst;
}

//memmove应对重叠的策略就是从后往前遍历
void *my_memmove(void* dst,const void*src,size_t n){
    char *s_dst=(char*)dst;
    char *s_src=(char*)src;

    if(s_dst>s_src&&(s_src+n>s_dst)){
        s_dst=s_dst+n-1;
        s_src=s_src+n-1;
        while(n){
            *s_dst=*s_src;
            --s_src;
            --s_dst;
            --n;
        }
    }
    else{
        while(n){
            *s_dst=*s_src;
            ++s_src;
            ++s_dst;
            --n;
        }
    }

    return dst;
}