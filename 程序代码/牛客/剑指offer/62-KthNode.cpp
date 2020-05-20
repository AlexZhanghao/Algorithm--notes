#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(pRoot==NULL||k<1) return NULL;
        dfsk(pRoot,k);
        if(node.size()<k) return NULL;
        return node[k-1];
    }

    void dfsk(TreeNode* root,int k){
        if(root==NULL) return;
        if(root->left!=NULL) dfsk(root->left,k);
        node.push_back(root);
        if(node.size()==k) return ;
        if(root->right!=NULL) dfsk(root->right,k);
    }

private:
    vector<TreeNode*> node;
};