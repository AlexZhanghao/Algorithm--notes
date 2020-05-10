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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root==NULL) return {};
       queue<TreeNode*> q;
       vector<int> out;
       q.push(root);
       while(!q.empty()){
           TreeNode* cur=q.front();
           q.pop();
           out.push_back(cur->val);
           if(cur->left!=NULL) q.push(cur->left);
           if(cur->right!=NULL) q.push(cur->right);
       }
       return out;
    }
};