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

class Solution {
public:
    int ant=0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
			return 0;
		}
        
        int left_node=0,right_node=0;
        //好好想一想，下面的递归其实完全没必要，可以直接将ant安放在depth中，就如官方做法那样
        left_node=diameterOfBinaryTree(root->left);
        right_node=diameterOfBinaryTree(root->right);

        return ant=max(depth(root->left)+depth(root->right),ant);
    }

    int depth(TreeNode* root){
		if (root == NULL) {
			return 0;
		}

        int left_depth=0,right_depth=0;
        left_depth=depth(root->left);
        right_depth=depth(root->right);
        return max(left_depth,right_depth)+1;
    }
};

class Solution2 {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) return 0; // 访问到空节点了，返回0
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};