#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str) {
		if ((sizeof(str) / sizeof(*str)) == 0) return true;
		char start = str[0];
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (matrix[i*cols + j] == str[0]) {
					vector<int> book(rows*cols, 0);
					if (dfs(matrix, rows, cols, i, j, 0, book, str)) return true;
				}
			}
		}
		return false;
	}

	bool dfs(char* matrix, int rows, int cols, int x, int y, int cur, vector<int>& book, char* str) {
		if (matrix[x*cols + y] != str[cur]) return false;
        //if((sizeof(str)/sizeof(*str))==cur) return true;
        //使用上面的牛客上死活通不过，需要用下面这种方式
        if (str[cur+1]==0) return true;
		book[x*cols + y] = 1;
		int dir_x[4] = { 0,0,-1,1 };
		int dir_y[4] = { -1,1,0,0 };
		for (int i = 0; i < 4; ++i) {
			int cur_x = x + dir_x[i];
			int cur_y = y + dir_y[i];
			if (cur_x < 0 || cur_x >= rows || cur_y < 0 || cur_y >= cols || book[cur_x*cols + cur_y] == 1) continue;
			if (dfs(matrix, rows, cols, cur_x, cur_y, cur + 1, book, str)) return true;
			book[cur_x*cols + cur_y] = 0;
		}
		return false;
	}
};