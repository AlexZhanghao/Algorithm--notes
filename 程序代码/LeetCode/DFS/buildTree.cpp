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
        if(preorder.size()==0) return nullptr;
        int root=0;
        return buildHelper(preorder,inorder,root,0,preorder.size()-1);
    }

    //pos指定preorder中根节点的位置，left和right指定inorder中的范围
    //注意这里pos作为应用传参在a->left结束后，pos的位置就已经指向了右子树的起始位置
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder,int &pos,int left,int right){
        if(pos>=preorder.size()) return nullptr;
        TreeNode* a=new TreeNode(preorder[pos]);
        int iroot=left;
        for(;iroot<=right;++iroot){
            if(inorder[iroot]==preorder[pos]) break;
        }
        if(left<=iroot-1)a->left=buildHelper(preorder,inorder,++pos,left,iroot-1);
        if(iroot+1<=right)a->right=buildHelper(preorder,inorder,++pos,iroot+1,right);
        return a;
    }
};