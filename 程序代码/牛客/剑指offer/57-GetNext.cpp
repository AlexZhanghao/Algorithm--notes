#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

//这题主要是运用中序遍历的性质不断迭代即可
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(pNode==NULL) return pNode;
        TreeLinkNode* root=NULL;
        if(pNode->right!=NULL){
            root=pNode->right;
            while(root->left!=NULL) root=root->left;
            return root;
        }
        else if(pNode->next!=NULL){
            root=pNode->next;
            if(pNode==root->left) return root;
            else{
                while(root->next!=NULL){
                    if(root==root->next->left) return root->next;
                    else root=root->next;
                }
            }
        }
        return NULL;
    }
};