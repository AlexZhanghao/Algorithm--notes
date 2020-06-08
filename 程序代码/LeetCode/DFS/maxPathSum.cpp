#include<iostream>
#include<vector>
#include<algorithm>
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
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        int val=INT_MIN;
        dfs(root,val);
        return val;
    }

    int dfs(TreeNode* root,int& val){
        if(root==nullptr) return 0;
        int left=dfs(root->left,val);
        int right=dfs(root->right,val);
        int dou=root->val+max(0,left)+max(0,right);
        int sig=root->val+max(0,max(left,right));
        val=max(val,dou);
        return sig;
    }
};