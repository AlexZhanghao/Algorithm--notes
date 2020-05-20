#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return;
        int mid=n/2;
        if(n%2==0){
            for(int i=0;i<mid;++i){
                for(int j=0;j<mid;++j){                    
                    swap(matrix[i][j],matrix[j][n-i-1]);
                    swap(matrix[i][j],matrix[n-i-1][n-j-1]);
                    swap(matrix[i][j],matrix[n-j-1][i]);
                }
            }
        }
        else{
            for(int i=0;i<mid;++i){
                for(int j=0;j<mid+1;++j){
                    swap(matrix[i][j],matrix[j][n-i-1]);
                    swap(matrix[i][j],matrix[n-i-1][n-j-1]);
                    swap(matrix[i][j],matrix[n-j-1][i]);
                }
            }
        }
    }
};

//这是那位力扣老哥的原版解，它这里一是变除法为右移，二是通过省去了谈论奇偶的麻烦
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) { return; }
        int r = (n>>1)-1; //左上角区域的最大行下标，
        int c = (n-1)>>1; //左上角区域的最大列下标，行列下标从 0 开始。
        for(int i = r; i >= 0; --i) {
            for(int j = c; j >= 0; --j) {
                swap(matrix[i][j], matrix[j][n-i-1]);
                swap(matrix[i][j], matrix[n-i-1][n-j-1]);
                swap(matrix[i][j], matrix[n-j-1][i]);
            }
        }
    }
};