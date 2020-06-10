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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        queue<TreeNode*> qr;
        int mindep=1;
        qr.push(root);
        

        while(!qr.empty()){
            int qsize=qr.size();
            for(int i=0;i<qsize;++i){
                TreeNode* node=qr.front();
                qr.pop();
                if(node->left==NULL&&node->right==NULL){
                    return mindep;
                }
                if(node->left!=NULL){
                    qr.push(node->left);                
                }
                if(node->right!=NULL){
                    qr.push(node->right);
                }
            }
            
            ++mindep;            
        }

        return mindep;
    }
};