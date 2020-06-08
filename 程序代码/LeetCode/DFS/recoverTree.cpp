#include<iostream>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root==nullptr) return;
        releft=nullptr;reright=nullptr;last=nullptr;
        dfs(root);
        if(releft&&reright){
            int ret=releft->val;
            releft->val=reright->val;
            reright->val=ret;
        }
    }

    void dfs(TreeNode* root){
        if(root==nullptr) return;

        dfs(root->left);
        if(last!=nullptr&&root->val < last->val){
			if (releft == nullptr) {
				releft = last;
				reright = root;
			}
			else {
				reright = root;
				return;
			}
        }

        //这一步必须放在给releft和reright赋值的后面，不然就会使releft和reright的值相同
        //因此dfs(root->right)后面不能设置releft和reright的赋值，这就是我之前一直出错的地方
        last=root;

        dfs(root->right);
    }

private:
    TreeNode* releft,*reright,*last;
};