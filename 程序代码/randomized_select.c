#include<iostream>
#include<randomized_quicksort.h>

double RandomizedSelect(double *A,p,r,i){
	if(p==r)
		return A[p];
		
	int q=RandomizedPartition(A,p,r);
	int k=q-p+1;
	
	if(i==k){
		return A[q];
	}else if(i<k){
		return RandomizedSelect(A,p,q-1,i);
	}else{
		return RandomizedSelect(A,q+1,r,i-k);
	}
}