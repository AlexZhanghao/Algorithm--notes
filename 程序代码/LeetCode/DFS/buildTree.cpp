#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        TreeNode* bintree=new TreeNode(preorder[0]);
        TreeNode* cur=bintree;
        int i=0;
        while(inorder[i]!=preorder[0]) ++i;
        vector<int> preleft;
        vector<int> preright;
        vector<int> inoleft;
        vector<int> inoright;
        for(int j=0;j<i;++j){
            preleft.push_back(preorder[j+1]);
            inoleft.push_back(inorder[j]);
        }
        for(int k=i+1;k<preorder.size();++k){
            preright.push_back(preorder[k]);
            inoright.push_back(inorder[k]);
        }
        bintree->left=buildTree(preleft,inoleft);
        bintree->right=buildTree(preright,inoright);
        return bintree;
    }
};

//这兄弟把建vector分别装左右部分的步骤省了，所以无论时间还是空间上都要好很多
class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return buildTree(preorder, pos, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int& pos, vector<int>& inorder, int left, int right) {
        if (pos >= preorder.size()) return 0;
        int i = left;
        for (i = left; i <= right; ++i) {
            if (inorder[i] == preorder[pos]) break;
        }
        TreeNode* node = new TreeNode(preorder[pos]);
        if (left <= i-1) node->left = buildTree(preorder, ++pos, inorder, left, i-1);  // 左子树
        if (i+1 <= right) node->right = buildTree(preorder, ++pos, inorder, i + 1, right);  // 右子树
        return node;
    }
};