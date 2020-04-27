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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL) return false;
        int bs=B->val;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){
            TreeNode* anode=q.front();
            if(anode->val==bs){
                if(dfs_comparison(anode,B)) return true;
            }
            q.pop();
            if(anode->left!=NULL) q.push(anode->left);
            if(anode->right!=NULL) q.push(anode->right);
        }

        return false;
    }

    bool dfs_comparison(TreeNode* a,TreeNode *b){
        if(a==NULL&&b!=NULL||a!=NULL&&b==NULL||a->val!=b->val) return false;
        if(b->left!=NULL){
            if(!dfs_comparison(a->left,b->left)) return false;
        }
        if(b->right!=NULL){
            if(!dfs_comparison(a->right,b->right)) return false;
        }
        return true;
    }
};