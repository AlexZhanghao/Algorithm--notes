#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        row=land.size();
        if(row==0) return {};
        col=land[0].size();
        for(int i=0;i<row;++i){
            book.push_back(vector<int>(col,0));
        }
        vector<int> out;
        
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(land[i][j]==0&&book[i][j]==0){
                    int count=0;
                    dfs(land,i,j,count);
                    out.push_back(count);
                }
            }
        }
        sort(out.begin(),out.end());
        return out;
    }

    void dfs(vector<vector<int>>& land,int x,int y,int &count){
        ++count;
        book[x][y]=1;
        int dir_x[8]={-1,1,0,0,-1,-1,1,1};
        int dir_y[8]={0,0,-1,1,-1,1,-1,1};
        int cur_x=0,cur_y=0;
        for(int i=0;i<8;++i){
            cur_x=x+dir_x[i];
            cur_y=y+dir_y[i];
            if(cur_x>=row||cur_x<0||cur_y>=col||cur_y<0||land[cur_x][cur_y]!=0||book[cur_x][cur_y]==1) continue;
            dfs(land,cur_x,cur_y,count);
        }
        return;
    }

private:
    vector<vector<int>> book;   
    int row,col;
};