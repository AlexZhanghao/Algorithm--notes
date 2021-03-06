#include<iostream>
#include<vector>

using namespace std;
//n表示油井的数量

void  PetroleumPipeline(double *x,double *y,int n){
	vector<double*> pipeline_array;
	int class_number=0;
	int median_number=0;
	int count=0;
	
	median_number=n/2;
	
	if(n%5>0){
		class_number=n/5+1;
	}else{
		class_number=n/5;
	}
	
	while(class_number>0){
		for(int i=0;i<5;++i){
			pipeline[count][i]=y[count*5+i];
		}
		count++;
		class_number--;
	}
	
	//Using insertion sorting to sort each subarray
	for(int j=0;j<count;j++){
		InsertionSort(pipeline[count]);
	}
	
	//finding the medians of each subarray
	double median[count+1]={0};
	double median_backups[count]={0};
	if(n%5>0){
		 for(int k=0;k<count-1;++k){
	    	median[k]=pipeline[count][2];
	    	median_backups[k]=pipeline[count][2];
	   }
	   median[count-1]=pipeline[count-1][n%5/2+1];
	}else{
	for(int k=0;k<count;++k){
	     median[k]=pipeline[count][2];
	     median_backups[k]=pipeline[count][2];
	  }
	}
	
	//finding the median of the median array 
	//and dividing the arrray into big and small parts on the basis of median
	int median_median_number=0;
	median_median_number=count/2;
	RandomizedSelect(median,0,count-1,median_median_number);
	median[count]=median_median_number;
	int demarcation_number=Partition(median,0,count);
	
	
}