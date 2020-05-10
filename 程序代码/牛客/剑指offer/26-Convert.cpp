#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//中序遍历
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr) return nullptr;
        pre = nullptr;
        dfs(pRootOfTree);
        return start;
    }

    void dfs(TreeNode* pRoot){
        if(pRoot==nullptr) return;
        dfs(pRoot->left);
        if(pre!=nullptr) pre->right=pRoot;
        else start=pRoot;
        pRoot->left=pre;
        pre=pRoot;
        dfs(pRoot->right);
    }

private:
    TreeNode* start;
    TreeNode* pre;
};