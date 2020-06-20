#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* p;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

void LeftRtate(TreeNode* root,TreeNode* x){
    if(x->right==NULL) return;

    TreeNode* y=x->right;
    x->right=y->left;
    if(y->left){
        y->left->p=x;
    }
    y->p=x->p;
    if(x==root){
        root=y;
    }
    else if(x==x->p->left){
        x->p->left=y;
    }
    else{
        x->p->right=y;
    }

    y->left=x;
    x->p=y;
}