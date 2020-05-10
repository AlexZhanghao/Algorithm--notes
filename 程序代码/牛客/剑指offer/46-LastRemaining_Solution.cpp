#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n==0) return 0;
        queue<int> q;
        for(int i=0;i<n;++i) q.push(i);
        int lastremainer=0;
        while(!q.empty()){
            int i=q.size();
            if(i==1){
                lastremainer=q.front();
                break;
            }
            //m=m%i;//这里导致m=1和0时混淆不清
            for(int j=0;j<m-1;++j){
                int k=q.front();
                q.pop();
                q.push(k);
            }
            q.pop();
        }
        return lastremainer;
    }
};

//这种题目叫约瑟夫环，可以递归解决
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n==0) return -1;
        if(n==1) return 0;
        return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};