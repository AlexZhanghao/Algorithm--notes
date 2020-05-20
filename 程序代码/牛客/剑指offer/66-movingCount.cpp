#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        if(threshold<0||rows<1||cols<1) return 0;
        queue<int> p,q;
        vector<vector<int>> book(rows,vector<int>(cols,0));
        int maxgrid=0;
        p.push(0);q.push(0); 
        book[0][0]=1;     
        while (!p.empty()&&!q.empty()){
            int cur_x=p.front();
            int cur_y=q.front();           
            ++maxgrid;
            p.pop();q.pop();
            int dir_x[4] = { 0,0,-1,1 };
		    int dir_y[4] = { -1,1,0,0 };
            for(int i=0;i<4;++i){
                int x=cur_x+dir_x[i];
                int y=cur_y+dir_y[i];
                if(x<0||x>=rows||y<0||y>=cols||book[x][y]==1||isoverboundary(threshold,x,y)) continue;
                //要尤其注意这里book记录的位置
                book[x][y]=1;
                p.push(x);q.push(y);
            }
        }
        
        return maxgrid;
    }

private:
    bool isoverboundary(int threshold, int x, int y){
        int i=0;
        while(x!=0){
            i+=x%10;
            x=x/10;
        }
        while(y!=0){
            i+=y%10;
            y=y/10;
        }
        return i>threshold;
    }
};