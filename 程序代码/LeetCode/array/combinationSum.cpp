#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        if(n<1) return {};
        sort(candidates.begin(),candidates.end());
        vector<int> book;
        int last_num=INT_MIN;
        dfs(candidates,target,book,last_num);
        return out;
    }

    void dfs(vector<int>& candidates, int target,vector<int>& book,int last_num){
        int n=candidates.size();
        for(int i=0;i<n;++i){
            //这一步是去重的精髓，假设candidates中包含2,3，则会出现{2,3}和{3,2}，这就造成了重复。
            //而我们现在以不减的顺序进行探测，这就避免了重复发生。
            if(i<last_num) continue;
            int k=target-candidates[i];
            book.push_back(candidates[i]);
            if(k==0) out.push_back(book);
            else if(k<0){
                //因为排序过，所以如果减这个数后都已经小于0了，而后面的数更大，就更不可能了，所以直接终止循环。
                book.pop_back();
                break;
            }
            else{
                dfs(candidates,k,book,candidates[i]);
            }
            book.pop_back();
        }
    }

private:
    vector<vector<int>> out;
};