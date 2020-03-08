#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(n==0){
        }
        else{
            for(int i=0;i<n;++i){
                A[m+i]=B[i];
            }
            sort(A.begin(),A.end());            
        }
    }
};

//官方题解给的双指法，值得积累，这里来搬运一波,
//不过它的做法是再建一个数组来放A和B中的元素，但我用了动态数组实在是不会用，
//这里改动了下，直接在A上操作，运行时间上有很大改善，内存相同。
class Solution2 {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int pa = m-1, pb = n-1,psum=m+n-1;
        while(pa!=-1||pb!=-1){
            if(pa==-1){
                A[psum--]=B[pb--];
            }
            else if(pb==-1){
                A[psum--]=A[pa--];
            }
            else{
                if(A[pa]<B[pb]){
                    A[psum--]=B[pb--];
                }else{
                    A[psum--]=A[pa--];
                }
            }
        }        
    }
};