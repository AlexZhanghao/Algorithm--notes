#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),parent(NULL),left(NULL),right(NULL){}
};

/*
有右子节点
右子节点有无左子节点
    无 —— 右子节点就是当前结点下一节
    有 —— 递归寻找右子节点的左子节点就是下一节点
无右子节点
    无父节点 —— 无下一结点
    有父节点
        当前结点作为父节点的左子节点 —— 下一结点为父节点
        当前结点作为父节点的右子节点 —— 向父节点递归寻找作为左子节点的结点就是下一节点
*/
TreeNode* nextnode(TreeNode* root){
    TreeNode* ptr=NULL;
    if(root->right){
        ptr=root->right;
        while(ptr->left) ptr=ptr->left;
    }
    else if(root->parent&&root==root->parent->left){
        ptr=root->parent;
    }
    else if(root->parent&&root==root->parent->right){
        TreeNode* p=root->parent;
        while(p->parent&&p!=p->parent->left) p=p->parent;
        if(p==p->parent->left) ptr=p->parent;
    }

    return ptr;
}