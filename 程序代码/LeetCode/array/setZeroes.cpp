#include<iostream>
#include<vector>

using namespace std;

//参考：https://leetcode-cn.com/problems/set-matrix-zeroes/solution/o1kong-jian-by-powcai/
//用matrix第一行和第一列记录该行该列是否有0,作为标志位。
//同时对于第一行,和第一列要设置一个标志位,为了防止自己这一行(一列)也有0的情况。
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        bool row_flag=false,col_flag=false;
        for(int i=0;i<row;++i){
            if(matrix[i][0]==0){
                row_flag=true;
                break;
            }
        }
        for(int j=0;j<col;++j){
            if(matrix[0][j]==0){
                col_flag=true;
                break;
            }
        }

        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<row;++i){
            for(int j=1;j<col;++j){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(row_flag){
            for(int i=0;i<row;++i){
                matrix[i][0]=0;
            }
        }
        if(col_flag){
            for(int j=0;j<col;++j){
                matrix[0][j]=0;
            }
        }
    }
};