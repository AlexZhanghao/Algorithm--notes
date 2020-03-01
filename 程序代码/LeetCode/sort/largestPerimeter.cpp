#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int asize=A.size();
        if(asize<3){
            return 0;
        }
        sort(A.begin(),A.end());
        for(int i=asize-3;i>-1;--i){
            if(A[i]+A[i+1]>A[i+2]){
                return A[i]+A[i+1]+A[i+2];
            }
        }
        return 0;
    }
};