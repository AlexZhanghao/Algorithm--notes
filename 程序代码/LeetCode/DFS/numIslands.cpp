#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        row=grid.size();
        if(row==0) return 0;
        col=grid[0].size();
        int out=0;
        for(int i=0;i<row;++i){
            book.push_back(vector<int>(col,0));
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]=='1'&&book[i][j]==0){
                    dfs(grid,i,j);
                    ++out;
                }
            }
        }
        return out;
    }

    void dfs(vector<vector<char>>& grid,int x,int y){
        book[x][y]=1;
        int dir_x[4]={-1,1,0,0};
        int dir_y[4]={0,0,-1,1};
        for(int i=0;i<4;++i){
            int cur_x=x+dir_x[i];
            int cur_y=y+dir_y[i];
            if(cur_x<0||cur_x>=row||cur_y<0||cur_y>=col||grid[cur_x][cur_y]=='0'||book[cur_x][cur_y]==1) continue;
            dfs(grid,cur_x,cur_y);
        }
        return;
    }

private:
    vector<vector<int>> book;
    int row,col;
};