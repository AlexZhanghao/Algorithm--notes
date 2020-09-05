#include<iostream>

using namespace std;

//alinged_malloc接受两个size_t类型的参数，
//size是分配的内存块字节数，alignment是对齐数目，
//返回指向对齐的内存块的void*指针。

void* alinged_malloc(size_t size,size_t alignment){
    //首先要检查alignment是否为2的整数次幂
    if(alignment&(alignment-1)){
        return nullptr;
    }
    else{
        //n个连续的自然数中一定有一个数可以被n整除。
        //为了能够找到size字节的alignment对齐的内存，至少要分配(size+alignment)字节的内存。
        //同时，为了能够有足够的空间来保存整个分配的内存的起始地址（即ptr）。
        //因此，还需要多分配一个指针占用字节数的内存，可用sizeof(void*)得到。
        void* ptr=malloc(sizeof(void*)+size+alignment);

        if(ptr){
            //在寻找alignment字节对齐的内存前，要先跳过为记录整个分配的内存的起始地址（即ptr的地址）保留的内存
            void* pstart=reinterpret_cast<void*>(reinterpret_cast<size_t>(ptr)+sizeof(void*));

            //从pstart向上寻找alignment对齐的内存块
            void* palignedbuf=reinterpret_cast<void*>((reinterpret_cast<size_t>(pstart)|(alignment))+1);
            
            //返回对齐的内存之前，先前移指针大小个字节来保存整个分配的内存的起始地址
            (static_cast<void**>(palignedbuf))[-1]=ptr;

            return palignedbuf;
        }
        else{
            return nullptr;
        }
    }
}

void aligned_free(void* palignedmemory){
    //从palignedmem前移指针大小个字节，得到整个分配的内存的地址
    //然后free内存
    free(reinterpret_cast<void*>((static_cast<void**>(palignedmemory))[-1]));
}