#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//前序遍历
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        //if(pRoot->left==NULL&&pRoot->right==NULL) return;
        //这里使用上面会出现越栈的情况，表示不太懂
        if (pRoot == NULL) return;
        TreeNode* mid=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=mid;

        if(pRoot->left!=NULL) Mirror(pRoot->left);
        if(pRoot->right!=NULL) Mirror(pRoot->right);
    }
};