#include<iostream>
#include<stdlib.h>

using namespace std;

//A�Ǵ��������飬p����ʼλ�ã�r����ֹλ��

int RandomizedQuicksort(A*,p,r){
	if(p<r){
		int q=RandomizedPartition(A,p,r);
		RandomizedQuicksort(A,p,q-1);
		RandomizedQuicksort(A,q+1,r);
	}
}

int RandomizedPartition(A*,p,r){
	
	int i=Random(p,r);
	Exchange(A[r],A[i]);
	return Partition(A,p,r);
}

int Partition(A*,p,r){
	int x=A[r];
	i=p-1;
	for(int j=p;j<r-1;++j){
		if(A[j]<x||A[j==x]){
			++i;
			Exchange(A[i],A[j]);
		}
	}
	Exchange(A[i+1],A[r]);
	return i+1;
}

void Exchange(int &a,int &b){
	int i=a;
	a=b;
	b=i;
}