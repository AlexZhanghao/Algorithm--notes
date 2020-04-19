#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct dir {
	int x;
	int y;
	dir(int i, int j) :x(i), y(j) {};
};

class Solution {
public:
	int movingCount(int m, int n, int k) {
		queue<dir> q;
		dir start(0, 0);
		int dir_x[2] = { 0,1 };
		int dir_y[2] = { 1,0 };
		memset(book, 0, sizeof(book));
		q.push(start);
		book[0][0] = 1;
		int max_step = 0;
		while (!q.empty()) {
			dir cur = q.front();
			q.pop();
			++max_step;
			for (int i = 0; i < 2; ++i) {
				int cur_x = cur.x + dir_x[i];
				int cur_y = cur.y + dir_y[i];
				if (cur_x < 0 || cur_x >= m || cur_y < 0 || cur_y >= n || is_out(cur_x, cur_y, k) || book[cur_x][cur_y] == 1) continue;				
				dir a(cur_x, cur_y);
				book[cur_x][cur_y] = 1;
				q.push(a);
			}
		}
		return max_step;
	}

	bool is_out(int x, int y, int k) {
		return (x / 10 + x % 10 + y / 10 + y % 10) > k;
	}

private:
	int book[100][100];
};