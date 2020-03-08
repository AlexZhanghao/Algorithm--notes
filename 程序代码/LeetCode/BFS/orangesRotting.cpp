#include<iostream>
#include<vector>
#include<queue>

using namespace std;

enum Color { white, gray, black };

struct vertex {
	Color color;
	int d;
	int p;
	int q;
	int i;
	int j;
	bool is_empty;
};

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {				
		int row_size = grid.size();
		int column_size = grid[0].size();	

		vertex v;
		vector<vertex> a(column_size,v);
		vector<vector<vertex>> grid_vertex(row_size,a);
		
		queue<vertex> Q;

		//将各个位置初始化
		for (int i = 0; i < row_size; ++i) {
			for (int j = 0; j < column_size; ++j) {
				if (grid[i][j] == 0) {
					grid_vertex[i][j].i = i;
					grid_vertex[i][j].j = j;
					grid_vertex[i][j].is_empty = true;
				}
				else if (grid[i][j] == 1) {
					grid_vertex[i][j].color = white;
					grid_vertex[i][j].d = INT_MAX;
					grid_vertex[i][j].p = 0;
					grid_vertex[i][j].q = 0;
					grid_vertex[i][j].i = i;
					grid_vertex[i][j].j = j;
					grid_vertex[i][j].is_empty = false;
				}
				else {
					grid_vertex[i][j].color = gray;
					grid_vertex[i][j].d = 0;
					grid_vertex[i][j].p = -1;
					grid_vertex[i][j].q = -1;
					grid_vertex[i][j].i = i;
					grid_vertex[i][j].j = j;
					grid_vertex[i][j].is_empty = false;
					Q.push(grid_vertex[i][j]);
				}
			}
		}

		while (!Q.empty()) {
			vertex u = Q.front();
			Q.pop();
			if (u.i > 0) {
				vertex &up = grid_vertex[u.i - 1][u.j];
                if(up.is_empty==false){
                    if (up.color == white) {
					Colour(up, u);
					Q.push(grid_vertex[up.i][up.j]);
				    }
                }
				
			}

			if (u.j > 0) {
				vertex &left = grid_vertex[u.i][u.j - 1];
                if(left.is_empty==false){
                    if (left.color == white) {
					Colour(left, u);
					Q.push(grid_vertex[left.i][left.j]);
				    }
                }				
			}

			if (u.i < row_size - 1) {
				vertex &below = grid_vertex[u.i + 1][u.j];
                if(below.is_empty==false){
                    if (below.color == white) {
					Colour(below, u);
					Q.push(grid_vertex[below.i][below.j]);
				    }
                }
			}
			
			if (u.j < column_size - 1) {
				vertex &right = grid_vertex[u.i][u.j + 1];
                if(right.is_empty==false){
                    if (right.color == white) {
					Colour(right, u);
					Q.push(grid_vertex[right.i][right.j]);
				    }
                }
				
			}			

			grid_vertex[u.i][u.j].color = black;
		}

		int short_distance = 0;
		for (int i = 0; i < row_size; ++i) {
			for (int j = 0; j < column_size; ++j) {
				if (grid_vertex[i][j].is_empty == false) {
					if (grid_vertex[i][j].d == INT_MAX) {
						return -1;
					}
					else {
						if (grid_vertex[i][j].d > short_distance) {
							short_distance = grid_vertex[i][j].d;
						}
					}
				}
			}
		}

		return short_distance;
	}

	void Colour(vertex &a, const vertex parent) {
		a.color = gray;
		a.d = parent.d + 1;
		a.p = parent.i;
		a.q = parent.j;
	}
};

//官方做法，这里他利用了行列数都不得大于10的条件
class Solution2 {
	int cnt;
	int dis[10][10];

    //这里很巧妙，下面的组合分别代表右、下、左、上
	int dir_x[4] = { 0, 1, 0, -1 };
	int dir_y[4] = { 1, 0, -1, 0 };

public:
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int> >Q;		
        memset(dis, -1, sizeof(dis));
		cnt = 0;
		int n = (int)grid.size(), m = (int)grid[0].size(), ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 2) {
					Q.push(make_pair(i, j));
					dis[i][j] = 0;
				}
				else if (grid[i][j] == 1) cnt += 1;
			}
		}
		while (!Q.empty()) {
			pair<int, int> x = Q.front(); Q.pop();
			for (int i = 0; i < 4; ++i) {
				int tx = x.first + dir_x[i];
				int ty = x.second + dir_y[i];

                //这套操作不得不说行云流水
				if (tx < 0 || tx >= n || ty < 0 || ty >= m || ~dis[tx][ty] || !grid[tx][ty]) continue;

				dis[tx][ty] = dis[x.first][x.second] + 1;
				Q.push(make_pair(tx, ty));
				if (grid[tx][ty] == 1) {
					cnt -= 1;
					ans = dis[tx][ty];
					if (!cnt) break;
				}
			}
		}
		return cnt ? -1 : ans;
	}
};
