//����A��ʾ��ɫ��������B��ʾ��ɫ�������ĸ���Ϊn
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