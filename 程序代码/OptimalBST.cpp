 #include<iostream>
#include<vector>

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

using namespace std;

void OptimalBST(int *p,int *q,int n,int **contribution,int **root_node){
    int **e=new int *[n+1];
    int **root=new int *[n+1];
    for(int i=0;i<n;++i){
        e[i]=new int[n+1];
        root[i]=new int[n+1];
    }

    for(int i=0;i<n;++i){
        e[i,i-1]=q[i-1];
    }
}