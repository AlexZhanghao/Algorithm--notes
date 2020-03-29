#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
	struct Coordinate {
		int x, y, step;
	};

	int maxDistance(vector<vector<int>>& grid) {
		int rsize = grid.size();
		if (rsize == 0) return 0;
		int csize = grid[0].size();
		int dir_x[4] = { -1,1,0,0 };
		int dir_y[4] = { 0,0,-1,1 };
		memset(is_find, 0, sizeof(is_find));
		queue<Coordinate> q;
		bool is_sea = false;
		int maxdis = 0;

		for (int i = 0; i < rsize; ++i) {
			for (int j = 0; j < csize; ++j) {
				if (grid[i][j] || is_find[i][j]) continue;
				bool is_end = false;
				q.push({ i,j,0 });
				is_find[i][j] = 1;

				while (!q.empty()) {
					auto curr = q.front();
					q.pop();
					if (grid[curr.x][curr.y] == 1) {
						is_end = true;
						break;
					}
					for (int k = 0; k < 4; ++k) {
						int di = curr.x + dir_x[k];
						int dj = curr.y + dir_y[k];
						if (di < 0 || di >= rsize || dj < 0 || dj >= csize || is_find[di][dj] == 1) continue;
						q.push({ di,dj,curr.step + 1 });
						is_find[di][dj] = 1;
						maxdis = max(maxdis, curr.step + 1);
					}
				}
				if (!is_end) {
					maxdis = 0;
				}
			}
		}
		return maxdis ? maxdis : -1;
	}

private:
	bool is_find[100][100];
};


class Solution2 {
public:
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate {
        int x, y, step;
    };

    int n, m;
    vector<vector<int>> a;

    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y) {
        memset(vis, 0, sizeof vis);
        queue <Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)) continue;
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny]) return f.step + 1;
                }
            }
        }
        return -1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }
};