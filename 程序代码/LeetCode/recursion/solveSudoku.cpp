#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int k = board[i][j] - 48;
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
		if (j > 8) {
			++i;
			j = 0;
		}
		if (i > 8) return true;
		if (board[i][j] != '.') {
			SudokuAlgorithm(board, i, j + 1);
		}
		if (board[i][j] == '.') {
			int box_index = (i / 3) * 3 + j / 3;
			for (int m = 1; m < 10; ++m) {
				if (!is_exist(m, i, j, box_index)) {
					board[i][j] = m + 48;
					int k = board[i][j] - 48;
					row[i][k] = 1;
					cloumn[j][k] = 1;
					box[box_index][k] = 1;
					if (SudokuAlgorithm(board, i, j + 1)) return true;
					board[i][j] = '.';
					row[i][k] = 0;
					cloumn[j][k] = 0;
					box[box_index][k] = 0;
				}
			}
		}
		return false;
	}

	bool is_exist(int m, int i, int j, int box_index) {
		return row[i][m] == 1 || cloumn[j][m] == 1 || box[box_index][m] == 1;
	}

private:
	int row[9][10] = { 0 };
	int cloumn[9][10] = { 0 };
	int box[9][10] = { 0 };
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