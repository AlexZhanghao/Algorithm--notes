#include<iostream>
#include<vector>
#include<unordered_map>

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> out;
        dfs(root,out);
        return out;
    }

    void dfs(TreeNode* root,vector<int> &out){
        if(root==NULL) return;
        if(root->left!=NULL) dfs(root->left,out);
        out.push_back(root->val);
        if(root->right!=NULL) dfs(root->right,out);
        return;
    }
};