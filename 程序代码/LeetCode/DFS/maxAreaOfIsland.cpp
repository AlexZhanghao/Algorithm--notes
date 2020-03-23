#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int is_find[50][50];

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(is_find, 0, sizeof(is_find));
        int row_size = grid.size();
		if (row_size ==0) {
			return 0;
		}

		int cloumn_size = grid[0].size();
        int max_area=0;
        for(int i=0;i<row_size;++i){
            for(int j=0;j<cloumn_size;++j){
                if(is_find[i][j]==1) continue;
                int area=DepthSearch(grid,i,j,row_size,cloumn_size);
                max_area=max(max_area,area);
            }
        }

        return max_area;
    }

    int DepthSearch(vector<vector<int>>& grid,int x,int y,int x_size,int y_size){
        if(is_find[x][y]==1){
            return 0;
        }
        else{
        is_find[x][y]=1;
        }

        if(grid[x][y]==0) return 0;

        int dir_x[4] = { -1,1,0,0 };
		int dir_y[4] = { 0,0,-1,1 };
        int subarea=1;

        for(int i=0;i<4;++i){
            if(x+dir_x[i]<0||x+dir_x[i]==x_size||y+dir_y[i]<0||y+dir_y[i]==y_size){}
            else{
                subarea+=DepthSearch(grid,x+dir_x[i],y+dir_y[i],x_size,y_size);
            }
        }
        return subarea;
    }
};


//官解给的stack版本的DFS
class Solution2 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i != grid.size(); ++i)
            for (int j = 0; j != grid[0].size(); ++j) {
                int cur = 0;
                stack<int> stacki;
                stack<int> stackj;
                stacki.push(i);
                stackj.push(j);
                while (!stacki.empty()) {
                    int cur_i = stacki.top(), cur_j = stackj.top();
                    stacki.pop();
                    stackj.pop();
                    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1)
                        continue;
                    ++cur;
                    grid[cur_i][cur_j] = 0;
                    int di[4] = {0, 0, 1, -1};
                    int dj[4] = {1, -1, 0, 0};
                    for (int index = 0; index != 4; ++index) {
                        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
                        stacki.push(next_i);
                        stackj.push(next_j);
                    }
                }
                ans = max(ans, cur);
            }
        return ans;
    }
};