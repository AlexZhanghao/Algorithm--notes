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

        queue<pair<TreeNode*,int>> qr;
        int mindep=1;
        pair<TreeNode*,int> p1(root,mindep);
        qr.push(p1);
        

        while(!qr.empty()){
            pair<TreeNode*,int> node=qr.front();
            //这里这一点才是画龙点睛的地方,因为break的时候，这里刚好就是break的那个元素对应的层数
            mindep=node.second;
            qr.pop();
            if(node.first->left==NULL&&node.first->right==NULL){
                break;
            }
            if(node.first->left!=NULL){
                qr.push(pair<TreeNode*,int>(node.first->left,mindep+1));                
            }
            if(node.first->right!=NULL){
                qr.push(pair<TreeNode*,int>(node.first->right,mindep+1));
            }
        }

        return mindep;
    }
};