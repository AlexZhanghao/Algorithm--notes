#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root,sum,path,0);
        return obj_path;       
    }

    void dfs(TreeNode* root,int obj,vector<int> path,int cur){
        if(root==NULL) return;
        cur+=root->val;
        path.push_back(root->val);
        if(obj>0&&cur>obj||obj<0&&cur<obj) return;
        if(root->left==NULL&&root->right==NULL&&cur==obj){ 
            obj_path.push_back(path);
            return;
        }  
        dfs(root->left,obj,path,cur);
        dfs(root->right,obj,path,cur);
    }

private:
    vector<vector<int>> obj_path;
};