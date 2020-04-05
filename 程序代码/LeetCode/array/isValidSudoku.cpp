#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int cloumn[9][9]={0};
        int box[9][9]={0};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    int k=board[i][j]-49;
                    int boxindex=(i/3)*3+j/3;
                    if(row[i][k]||cloumn[j][k]||box[boxindex][k]) return false;
                    row[i][k]=1;
                    cloumn[j][k]=1;
                    box[boxindex][k]=1;
                }
            }
        }
        return true;
    }
};