#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		memset(row,0,sizeof(row));
		memset(cloumn,0,sizeof(cloumn));
		memset(box,0,sizeof(box));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int k = board[i][j] - 49;
					int box_index = (i / 3) * 3 + j / 3;
					row[i][k] = 1;
					cloumn[j][k] = 1;
					box[box_index][k] = 1;
				}
			}
		}
		SudokuAlgorithm(board, 0, 0);
	}

	bool SudokuAlgorithm(vector<vector<char>> &board, int i, int j) {
		//如果一列走完则换行
		if(j==9){
			return SudokuAlgorithm(board,i+1,0);
		}
		//如果行走完则说明已找到可行解
		if(i==9){
			return true;
		}

		int box_index=(i / 3) * 3 + j / 3;
		for(char m='1';m<='9';++m){
			if(board[i][j]=='.'){
				//检查是否符合数独的性质
				if(is_exist(m-49,i,j,box_index)) continue;
				//在把i行j列更新后将book数组也更新
				board[i][j]=m;
				row[i][m-49]=1;
				cloumn[j][m-49]=1;
				box[box_index][m-49]=1;
				//进行下一次递归
				if(SudokuAlgorithm(board,i,j+1)) return true;
				//如果上面没返回true，说明这个m是不行的，回溯一下后尝试下一组，这里注意要将book数组一同恢复
				board[i][j]='.';
                row[i][m-49]=0;
				cloumn[j][m-49]=0;
				box[box_index][m-49]=0;
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

int main() {
	vector<char> a = { '5', '3', '.', '.', '7', '.', '.', '.', '.' };
	vector<char> b = { '6', '.', '.', '1', '9', '5', '.', '.', '.' };
	vector<char> c = { '.', '9', '8', '.', '.', '.', '.', '6', '.' };
	vector<char> d = { '8', '.', '.', '.', '6', '.', '.', '.', '3' };
	vector<char> e = { '4', '.', '.', '8', '.', '3', '.', '.', '1' };
	vector<char> f = { '7', '.', '.', '.', '2', '.', '.', '.', '6' };
	vector<char> g = { '.', '6', '.', '.', '.', '.', '2', '8', '.' };
	vector<char> h = { '.', '.', '.', '4', '1', '9', '.', '.', '5' };
	vector<char> i = { '.', '.', '.', '.', '8', '.', '.', '7', '9' };
	vector<vector<char>> m = { a,b,c,d,e,f,g,h,i };
	Solution s;
	s.solveSudoku(m);
	system("pause");
	return 1;
}