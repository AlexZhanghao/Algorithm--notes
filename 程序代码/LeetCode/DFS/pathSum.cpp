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
        if(root==NULL) return {};
        vector<vector<int>> ret;
        vector<int> nums;
        dfs(root,ret,nums,sum,0);
        return ret;
    }

    void dfs(TreeNode* root,vector<vector<int>>& ret,vector<int>& nums,int sum,int cur){
        if(root==NULL) return;

        cur+=root->val;
        nums.push_back(root->val);
        if(root->left){
            dfs(root->left,ret,nums,sum,cur);
        }
        if(root->right){
            dfs(root->right,ret,nums,sum,cur);
        }
        if(root->left==NULL&&root->right==NULL&&cur==sum){
            ret.push_back(nums);
        }
        nums.pop_back();
        return;
    }
};