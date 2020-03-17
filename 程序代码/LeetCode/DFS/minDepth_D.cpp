#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        stack<int> sr;
        sr.push(root->val);
        int mindep=INT_MAX;

        return depth(root,sr);               
    }

    int depth(TreeNode *root,stack<int> sr){
        if(root==NULL){
            return 0;
        }

        int mindep=INT_MAX;
        if(!sr.empty()){
            sr.pop();
            if(root->left!=NULL){
                sr.push(root->left->val);
                mindep=min(depth(root->left,sr),mindep);
            }
            if(root->right!=NULL){
                sr.push(root->right->val);
                mindep=min(depth(root->right,sr),mindep);
            }
            if(root->left==NULL&&root->right==NULL){
                return 1;
            }
        }

        return mindep+1;
    }
};