#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int* fac=new int[n+1];
        memset(fac,0,sizeof(fac));

        fac[0]=1;
        for(int i=1;i<n+1;++i){
            fac[i]=fac[i-1]*i;
        }

        vector<int> count;
        vector<int> used(n+1,0);
        dfs(0,n,k,fac,used,count);

        delete []fac;
        string ret;
        for(int i=0;i<n;++i) ret+=count[i]+'0';
        return ret;
    }

    void dfs(int cur,int n,int k,int *fac,vector<int>& used,vector<int>&count){
        if(cur==n) return;

        //还未确定的数字的全排列的个数，第 1 次进入的时候是 n - 1
        int cnt=fac[n-1-cur];
        for(int i=1;i<n+1;++i){
            if(used[i]) continue;

            if(cnt<k){
                k-=cnt;
                continue;
            }
            count.push_back(i);
            used[i]=true;
            dfs(cur+1,n,k,fac,used,count);
        }
    }
};