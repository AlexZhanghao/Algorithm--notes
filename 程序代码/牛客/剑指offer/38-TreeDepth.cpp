#include<iostream>
#include<vector>
#include<algorithm>

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
    int TreeDepth(TreeNode* pRoot){
        if(pRoot==NULL) return 0;
        dfs(pRoot,0);
        return max_depth;
    }

    void dfs(TreeNode *root,int dep){
        if(root==NULL) return;
        ++dep;
        max_depth=max(max_depth,dep);
        if(root->left!=NULL) dfs(root->left,dep);
        if(root->right!=NULL) dfs(root->right,dep);
    }

private:
    int max_depth=0;
};