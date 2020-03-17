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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }

        queue<TreeNode*> qnt;
        vector<vector<int>> lorder;
        int level_length=0;
        qnt.push(root);
        while(!qnt.empty()){
            level_length=qnt.size();
            vector<int> a;
            for(int i=0;i<level_length;++i){
                TreeNode *node=qnt.front();
                qnt.pop;
                if(node->left!=NULL){
                    qnt.push(node->left);
                }
                if(node->right!=NULL){
                    qnt.push(node->right);
                }
                a.push_back(node->val);
            }
            lorder.push_back(a);
        }
        return lorder;
    }
};