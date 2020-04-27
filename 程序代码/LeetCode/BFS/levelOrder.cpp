#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//这里在2的基础上运用栈做辅助即可
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        vector<vector<int>> out;
        bool is_left=false;
        while(!q.empty()){
            TreeNode* cur;
            vector<int> a;
            int qsize=q.size();
            for(int i=0;i<qsize;++i){
                cur=q.front();
                a.push_back(cur->val);
                s.push(cur);
                q.pop();
            }

            if(is_left){
                for(int i=0;i<qsize;++i){
                    cur=s.top();
                    s.pop();
                    if(cur->left!=NULL) q.push(cur->left);
                    if(cur->right!=NULL) q.push(cur->right);                    
                }
                is_left=false;
            }
            else{
                for(int i=0;i<qsize;++i){
                    cur=s.top();
                    s.pop();
                    if(cur->right!=NULL) q.push(cur->right);
                    if(cur->left!=NULL) q.push(cur->left);                                       
                }
                is_left=true;
            }
            out.push_back(a);
        }
        return out;
    }
};