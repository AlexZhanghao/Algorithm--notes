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

//自底向上的做法
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int depth=0;
        return helper(root,depth);
    }

    bool helper(TreeNode* root,int &depth){
        if(root==NULL) return true;
        int left_dep=0,right_dep=0;
        if(!helper(root->left,left_dep)) return false;
        if(!helper(root->right,right_dep)) return false;
        depth=max(left_dep,right_dep)+1;
        return (abs(left_dep-right_dep)<=1);        
    }
};

//另一种写法
class Solution2 {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        return (dfs(root)==-1)?false:true;
    }

    int dfs(TreeNode* root){
        if(root) return 0;

        int left_dep=dfs(root->left);
        if(left_dep==-1) return -1;
        int right_dep=dfs(root->right);
        if(right_dep==-1) return -1;

        return abs(left_dep-right_dep)<2?max(left_dep,right_dep)+1:-1;
    }
};