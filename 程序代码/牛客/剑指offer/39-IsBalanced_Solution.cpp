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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right)&&(abs(dfs(pRoot->left)-dfs(pRoot->right))>1);
    }

    int dfs(TreeNode *root){
        if(root==NULL) return 0;
        return max((dfs(root->left)+1),dfs(root->right)+1);
    }
};