#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        row=matrix.size();
        if(row==0) return{};
        col=matrix[0].size();
        vector<vector<int>> out(row,vector<int> (col,0));
        queue<pair<int,int>> q;
               
        int dir_x[4]={-1,1,0,0};
        int dir_y[4]={0,0,-1,1};
        //先将与0靠近的1(也就是最外围的1)的深度设为1，并加入队列
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){                
                if(matrix[i][j]==0){
                    for(int k=0;k<4;++k){
                        int cur_x=i+dir_x[k];
                        int cur_y=j+dir_y[k];
                        if(cur_x<0||cur_x>=row||cur_y<0||cur_y>=col||matrix[cur_x][cur_y]==0||out[cur_x][cur_y]==1) continue;
                        out[cur_x][cur_y]=1;
                        q.push(make_pair(cur_x,cur_y));
                    }
                }
            }
        }

        while (!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int cur_x=x+dir_x[i];
                int cur_y=y+dir_y[i];
                if(cur_x<0||cur_x>=row||cur_y<0||cur_y>=col||matrix[cur_x][cur_y]==0||out[cur_x][cur_y]!=0) continue;
                out[cur_x][cur_y]=out[x][y]+1;
                q.push(make_pair(cur_x,cur_y));
            }
        }
        
        return out;
    }

private:
    int row,col;
};