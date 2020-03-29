#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int r_size=grid.size();
        if(r_size==0) return 0;
        int c_size=grid[0].size();
        int dir_x[4] = { -1,1,0,0 };
		int dir_y[4] = { 0,0,-1,1 };
        int sfarea=0;

        for(int i=0;i<r_size;++i){
            for(int j=0;j<c_size;++j){
                if(grid[i][j]!=0){
                    sfarea+=2;
                    for(int k=0;k<4;++k){
                        int tx=i+dir_x[k];
                        int ty=j+dir_y[k];
                        if(tx>=0&&tx<r_size&&ty>=0&&ty<c_size){
                            if(grid[i][j]>grid[tx][ty]){
                                sfarea+=(grid[i][j]-grid[tx][ty]);
                            }                           
                        }
                        else{
                            sfarea+=grid[i][j];
                        }
                    }
                }
            }
        }
        return sfarea;
    }
};