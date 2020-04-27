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

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0) return NULL;       
        TreeNode* root=new TreeNode(pre[0]);
        if(pre.size()==1) return root;
        vector<int> pleft,pright,vleft,vright;
        int count=0;
        while(vin[count]!=pre[0]){
            pleft.push_back(pre[count+1]);
            vleft.push_back(vin[count]);
            ++count;
        }
        for(int i=count+1;i<pre.size();++i){
            pright.push_back(pre[i]);
            vright.push_back(vin[i]);
        }
        root->left=reConstructBinaryTree(pleft,vleft);
        root->right=reConstructBinaryTree(pright,vright);
        return root;
    }
};