#include<iostream>
#include<vector>

#define INT_MAX 0x7fffffff

using namespace std;

double CutRod(double *p,int n){
    if(n==0){
        return 0;
    }
    int q=-INT_MAX;
    double k=0;

    for(int i=0;i<n;++i){
        k=p[i]+CutRod(p,n-i-1);
      if(q<k){
          q=k;
      }
    }
}

//带备忘录自顶向下的方法
double MemoizedCutRod(double *p,int n){
    double* r=new double [n];
    for(int i=0;i<n;++i){
        r[i]=-INT_MAX;
    }

    double biggest_benefit=MemoizedCutRodAux(p,n,r);
    delete [] r;
    return biggest_benefit;
}

double MemoizedCutRodAux(double *p,int n,double *r){
    if (r[n]>0){
        return r[n];
    }

    double q;
    double k=0;
    if(n==0){
        q=0;
    }else{
        q=-INT_MAX;
        for(int i=0;i<n;++i){
           k=p[i]+ MemoizedCutRodAux(p,n-i+1,r);
        }
    }

    r[n]=q;
    return q;
}

//自底向上的方法
double BottomUpRod(double *p,int n){
    double* r=new double [n];
    r[0]=0;

    double q;
    int k=0;
    for(int i=0;i<n;++i){
        q=-INT_MAX;
        for(int j=0;j<i;++j){
            k=p[i]+r[j-i];
            if(k>q){
                q=k;
            }
        }
        r[i]=q;
    }

    int biggest_benefit=r[n];
    delete [] r;
    return biggest_benefit;
}