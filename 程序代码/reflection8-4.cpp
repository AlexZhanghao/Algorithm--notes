//数组A表示红色壶，数组B表示蓝色壶，壶的个数为n
#define n quantity
#define A red pot
#define B blue pot

void PotMap(double *A,double *B){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;++j){
			if(A[i]==B[j]){
				B[j]=B[i];
				B[i]=A[i];
				break;
			}
		}
	}
}