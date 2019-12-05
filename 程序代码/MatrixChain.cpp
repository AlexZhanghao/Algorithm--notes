#include<iostream>
#include<vector>

using namespace std;

//返回数组的长度
#define foo(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MAX 0x7fffffff

void MatrixChainOrder(int *p,int **bestprice,int **breakpoint){
    int n=foo(p);

    //创建多维动态数组
    int** m=new int*[n];
    int** s=new int*[n];
    for(int i=0;i<n;++i){
        m[i]=new int[n];
        s[i]=new int[n];
    }

    int j=0;
    int q=0;
    for(int i=0;i<n;++i){
        m[i][i]=0;
    }
    for(int l=1;l<n;++l){
        for(int i=0;i<n-l+1;++i){
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<j;++k){
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    bestprice=m;
    breakpoint=s;

    //将创建的动态多维数组删除
    for(int i=0;i<n;++i){
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
}