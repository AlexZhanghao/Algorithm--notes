#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		cloumn = board[0].size();
		char start = word[0];
		int i, j, cur;
		for (i = 0; i < row; ++i) {
			for (j = 0; j < cloumn; ++j) {
				if (board[i][j] == start) {
					if (dfs(board, word, i, j, 0)) return true;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>>& board, string word, int x, int y, int step) {
		//下面两个if的顺序不能颠倒，不然比目标长度少一个的word也能通过
		if (board[x][y] != word[step]) return false;
		if (step == word.size() - 1) return true;		
		//printf("%s\n", board[x][y]);
		cout << board[x][y] <<" "<<step<<endl;
		//这里用的很妙，化解了回溯时与记录的冲突问题
		int tem = board[x][y]; board[x][y] = 0;
		int dir_x[4] = { -1,1,0,0 };
		int dir_y[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; ++i) {
			int cur_x = x + dir_x[i];
			int cur_y = y + dir_y[i];
			if (cur_x < 0 || cur_x >= row || cur_y < 0 || cur_y >= cloumn || board[cur_x][cur_y] == 0) continue;
			if (dfs(board, word, cur_x, cur_y, step + 1)) return true;			
		}
		board[x][y] = tem;
		return false;
	}

private:
	int row;
	int cloumn;
};