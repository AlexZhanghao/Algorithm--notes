#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        if(n==1) return {nums};
        unordered_set<int> book;      
        for(int i=0;i<n;++i){
            vector<int> ret;
            book.insert(nums[i]);
            ret.push_back(nums[i]);
            dfs(nums,book,ret);
            book.erase(nums[i]);
        }
        return out;
    }

    void dfs(vector<int>& nums,unordered_set<int> &book,vector<int> &ret){
        if(ret.size()==nums.size()){
            out.push_back(ret);
            return;
        } 
        for(int i=0;i<nums.size();++i){
            if(book.count(nums[i])) continue;
            ret.push_back(nums[i]);
            book.insert(nums[i]);
            dfs(nums,book,ret);
            ret.pop_back();
            book.erase(nums[i]);
        }
        return;
    }

private:
    vector<vector<int>> out;
};

//不使用哈希表
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return {};
        if(n==1) return {nums};
        bool *book=new bool[n];
        //memset(book,0,sizeof(book)/sizeof(*book));

        //这里要是用上面的memset，在最后delete的时候就会报错，
        //百度后发现原因在于memcpy的时候，copy的大小超出了目标数组的大小，
        //改成下面这种形式或者把bool换成int即可正确运行，估计是和对齐有关系。
        for (int i = 0; i < n; ++i) {
			book[i] = false;
		}
        for(int i=0;i<n;++i){
            vector<int> ret;
            book[i]=true;
            ret.push_back(nums[i]);
            dfs(nums,book,ret);
            book[i]=false;
        }
        delete []book;
        return out;
    }

    void dfs(vector<int>& nums,bool *book,vector<int> &ret){
        if(ret.size()==nums.size()){
            out.push_back(ret);
            return;
        } 
        for(int i=0;i<nums.size();++i){
            if(book[i]==true) continue;
            ret.push_back(nums[i]);
            book[i]=true;
            dfs(nums,book,ret);
            ret.pop_back();
            book[i]=false;
        }
        return;
    }

private:
    vector<vector<int>> out;
};