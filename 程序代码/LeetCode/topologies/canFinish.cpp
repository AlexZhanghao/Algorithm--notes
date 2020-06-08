#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //入度
        vector<int> indegree(numCourses,0);
        //邻接表
        vector<vector<int>> adjacency(numCourses);
        queue<int> q;
        int num=numCourses;
        for(int i=0;i<prerequisites.size();++i){
            ++indegree[prerequisites[i][0]];
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;++i){
            if(indegree[i]==0){
                q.push(i);
                --num;
            }
        }

        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0;i<adjacency[cur].size();++i){
                if(--indegree[adjacency[cur][i]]==0){
                    q.push(adjacency[cur][i]);
                    --num;
                }
            }
        }

        if(num==0) return true;
        return false;
    }
};