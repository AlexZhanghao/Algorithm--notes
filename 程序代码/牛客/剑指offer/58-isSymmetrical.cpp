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

//需注意这里空的时候返回true
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot==NULL) return true;
        return Mirror(pRoot->left,pRoot->right);
    }

private:
    bool Mirror(TreeNode* pleft,TreeNode* pright){
        if(pleft!=NULL&&pright!=NULL){
            if(pleft->val!=pright->val||!Mirror(pleft->left,pright->right)||!Mirror(pleft->right,pright->left)) return false;
        }
        else if(pleft==NULL&&pright==NULL) return true;
        else return false;
        return true;
    }
};