#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //下面这么做是区分matrix的奇偶
        int row=n/2;
        int col=(n+1)/2;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[i][j],matrix[n-i-1][n-j-1]);
                swap(matrix[i][j],matrix[n-j-1][i]);
            }
        }

        return;
    }
};

//这是那位力扣老哥的原版解，它这里变除法为右移
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

//解法2，两次翻转，这个解法可能更加接地气一点
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int half=(n+1)/2;
        for(int i=0;i<half;++i){
            for(int j=0;j<n;++j){
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }

        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};