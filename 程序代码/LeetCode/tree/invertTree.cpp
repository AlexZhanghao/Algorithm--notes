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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        Invert(root);
        return root;
    }

    void Invert(TreeNode *root){
        if(root->left==NULL&&root->right==NULL) return;
        else if(root->left==NULL&&root->right!=NULL){
            root->left=root->right;
            root->right=NULL;
            Invert(root->left);
        }
        else if(root->left!=NULL&&root->right==NULL){
            root->right=root->left;
            root->left=NULL;
            Invert(root->right);
        }
        else{
            TreeNode* a=root->left;
            root->left=root->right;
            root->right=a;
            Invert(root->left);
            Invert(root->right);
        }
        return;
    }
};