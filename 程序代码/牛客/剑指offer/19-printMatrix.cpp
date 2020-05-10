#include<iostream>
#include<vector>

using namespace std;

//一次循环搞完一整圈会好处理点
class Solution {
public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        int row=matrix.size();
        int cloumn=matrix[0].size();
        int leftup=1,leftdown=0,rightup=0,rightdown=0;
        int top=0,down=row-1,left=0,right=cloumn-1;
        vector<int> out;
        while(top<=down&&left<=right){
            for(int i=left;i<=right;++i) out.push_back(matrix[top][i]);
            ++top;
            
            if(top<=down&&left<=right){
                for(int j=top;j<=down;++j) out.push_back(matrix[j][right]);
                --right;
            }

            if(top<=down&&left<=right){
                for(int p=right;p>=left;--p) out.push_back(matrix[down][p]);
                --down;
            }

            if(top<=down&&left<=right){
                for(int q=down;q>=top;--q) out.push_back(matrix[q][left]);
                ++left;
            }
        }

        return out;
    }
};