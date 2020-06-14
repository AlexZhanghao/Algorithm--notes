#include<iostream>
#include<vector>

using namespace std;
int n,m;

int dir_x[4]={-1,1,0,0};
int dir_y[4]={0,0,-1,1};

void dfs(vector<vector<int>> &land,vector<vector<int>> &book,int &count,int sum,int x,int y){
    if(sum==0){
        ++count;
        return;
    }

    --sum;
    int next_x=0,next_y=0;
    if(y=m-1){
        next_x=x+1;
        next_y=0;
    }
    if(land[x][y]==0){
        dfs(land,book,count,sum,next_x,next_y);
    }
    else{
        bool is_plant=true;
        for(int i=0;i<4;++i){
            int cur_x=x+dir_x[i];
            int cur_y=y+dir_y[i];
            if(book[cur_x][cur_y]==1) is_plant=false;
        }
        
        if(is_plant){
            dfs(land,book,count,sum,next_x,next_y);
            book[x][y]=1;
            dfs(land,book,count,sum,next_x,next_y);
        }
        else dfs(land,book,count,sum,next_x,next_y);
    }
}

int main(){
    n=0;m=0;
    while(cin>>n>>m){
        vector<vector<int>> land(n,vector<int>(m,0));
        vector<vector<int>> book(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>land[i][j];
            }
        }
        int count=0;
        int sum=n*m;
        dfs(land,book,count,sum,0,0);
    }

}