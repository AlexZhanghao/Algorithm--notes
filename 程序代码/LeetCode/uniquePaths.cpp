#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0){
            return 0;
        }

        vector<int> line;
        for(int i=0;i<m;++i){
            line.push_back(0);
        }

        vector<vector<int>> paths(n,line);

        //由于行进方向只能说向右或者向下，因此第一行和第一列都只能有一条路线
        for(int i=0;i<m;++i){
            paths[0][i]=1;
        }
        for(int j=0;j<n;++j){
            paths[j][0]=1;
        }

        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                paths[i][j]=paths[i-1][j]+paths[i][j-1];
            }
        }

        return paths[n-1][m-1];
    }
};