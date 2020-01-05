#include<iostream>
#include<string>
#include<vector>

using namespace std;

//双指针法
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int n = A.size();
		int *i = &A[0];
		int *j = &A[1];

		int p = 1;
		for (int k = 0; k < n; k += 2) {
			i = &A[k];
			if (isOdd(i)) {
				while (isOdd(j)&& p < n - 2) {					
					p += 2;
					j = &A[p];
				}
				if (isEven(j)) {
					Exchange(i, j);
				}
			}
			
		}
		return A;
	}

    bool isOdd(int *i){
        return *i%2==1;
    }

    bool isEven(int *i){
        return *i%2==0;
    }

    void Exchange(int *i,int *j){
        int p=*i;
        *i=*j;
        *j=p;
    }
};

int main(){
    vector<int> A={4,2,5,7};
    Solution s;
    s.sortArrayByParityII(A);
    for(int i=0;i<A.size();++i){
        cout<<A[i]<<"   ";
    }
    return 1;
}