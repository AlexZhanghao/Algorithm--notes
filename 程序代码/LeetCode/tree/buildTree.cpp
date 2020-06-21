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

//通过前中序遍历构造二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return nullptr;
        int n=inorder.size();

        return helper(preorder,inorder,0,n,0,n);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright) {
        if(ileft>=iright||pleft>=pright) return NULL;

        int a=preorder[pleft];
        TreeNode* root=new TreeNode(a);
        int i=ileft;
        while(i<iright&&inorder[i]!=a) ++i;
        int step=i-ileft;
        root->left=helper(preorder,inorder,pleft+1,pleft+step+1,ileft,i);
        root->right=helper(preorder,inorder,pleft+step+1,pright,i+1,iright);

        return root;
    }
};

//通过中后序构造二叉树
class Solution2 {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		if (n < 1) return nullptr;

		return helper(inorder, postorder, 0, n , 0, n );
	}

	TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int ileft, int iright, int pleft, int pright) {
		if (pleft >= pright || ileft >= iright) return NULL;

		int a = postorder[pright-1];
		TreeNode* root = new TreeNode(a);
		int i = ileft;
		while (i < iright && inorder[i] != a) ++i;
        int step=i-ileft;
		root->left = helper(inorder, postorder, ileft, i , pleft, pleft+step);
		root->right = helper(inorder, postorder, i+1 , iright, pleft+step, pright-1);
        
		return root;
	}
};