#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> out;

        out.push_back(root->val);
        while(!q.empty()){
            int qsize=q.size();

            bool is_in=false;
            int a=0;
            for(int i=0;i<qsize;++i){
                TreeNode* cur=q.front();
                q.pop();
                
                if(cur->left){
                    a=cur->left->val;
                    q.push(cur->left);
                    is_in=true;
                }
                if(cur->right){
                    a=cur->right->val;
                    q.push(cur->right);
                    is_in=true;
                }
                
            }
            if(is_in) out.push_back(a);
        }
        return out;
    }
};