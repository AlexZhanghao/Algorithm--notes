#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int row_size = grid.size();
		if (row_size ==0) {
			return 0;
		}

		int cloumn_size = grid[0].size();
		queue<pair<int, int>> cnt;
		int dir_x[4] = { -1,1,0,0 };
		int dir_y[4] = { 0,0,-1,1 };
		int maxarea = 0;
		//这里维护一个容器，用来记录岛屿是否被搜索过
		vector<int> a(cloumn_size, 0);
		vector<vector<int>> is_find(row_size, a);


		for (int i = 0; i < row_size; ++i) {
			for (int j = 0; j < cloumn_size; ++j) {
				if (is_find[i][j] == 1) continue;
				cnt.push(make_pair(i, j));
				int currentarea = 0;
				while (!cnt.empty()) {
					pair<int, int> current_island = cnt.front();
					cnt.pop();

					
                    if (grid[current_island.first][current_island.second] == 0||is_find[current_island.first][current_island.second]==1) {				
						continue;
					}
					else {
						++currentarea;
					}
					is_find[current_island.first][current_island.second] = 1;

					for (int i = 0; i < 4; ++i) {
						int cx = current_island.first + dir_x[i];
						int cy = current_island.second + dir_y[i];

						if (cx < 0 || cx >= row_size || cy < 0 || cy >= cloumn_size || is_find[cx][cy] == 1) continue;

						cnt.push(make_pair(cx, cy));
					}
				}
				maxarea = max(currentarea, maxarea);
			}
		}
		return maxarea;
	}
};

class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                queue<int> queuei;
                queue<int> queuej;
                queuei.push(i);
                queuej.push(j);
                while (!queuei.empty()) {
                    int cur_i = queuei.front(), cur_j = queuej.front();
                    queuei.pop();
                    queuej.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                        continue;
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        queuei.push(next_i);
                        queuej.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        return ans;
    }
};