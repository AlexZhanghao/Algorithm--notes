#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<int>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != 0) {
					int k = board[i][j] - 1;
					int box_index = (i / 3) * 3 + j / 3;
					row[i][k] = 1;
					cloumn[j][k] = 1;
					box[box_index][k] = 1;
				}
			}
		}
		SudokuAlgorithm(board, 0, 0);
	}

	bool SudokuAlgorithm(vector<vector<int>> &board, int i, int j) {
		//如果一列走完则换行
		if(j==9){
			return SudokuAlgorithm(board,i+1,0);
		}
		//如果行走完则说明已找到可行解
		if(i==9){
			return true;
		}

		int box_index=(i / 3) * 3 + j / 3;
		for(int m=1;m<=9;++m){
			if(board[i][j]==0){
				//检查是否符合数独的性质
				if(is_exist(m-1,i,j,box_index)) continue;
				//在把i行j列更新后将book数组也更新
				board[i][j]=m;
				row[i][m-1]=1;
				cloumn[j][m-1]=1;
				box[box_index][m-1]=1;
				//进行下一次递归
				if(SudokuAlgorithm(board,i,j+1)) return true;
				//如果上面没返回true，说明这个m是不行的，回溯一下后尝试下一组，这里注意要将book数组一同恢复
				board[i][j]=0;
                row[i][m-1]=0;
				cloumn[j][m-1]=0;
				box[box_index][m-1]=0;
			}
			else{
				return SudokuAlgorithm(board,i,j+1);
			}
		}

		//如果穷举完9个字母都没得到解就说明这个数独没有解，所以最后返回false
		return false;
	}

	bool is_exist(int m, int i, int j, int box_index) {
		return row[i][m] == 1 || cloumn[j][m] == 1 || box[box_index][m] == 1;
	}

private:
	int row[9][9] = { 0 };
	int cloumn[9][9] = { 0 };
	int box[9][9] = { 0 };
};

int main(){
    vector<vector<int>> sudo(9,vector<int>(9,0));

    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>sudo[i][j];
        }
    }

    Solution s;
    s.solveSudoku(sudo);

    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            printf("%d ",sudo[i][j]);
            //cout<<sudo[i][j]<<" ";
        }
        cout<<endl;
    }
}