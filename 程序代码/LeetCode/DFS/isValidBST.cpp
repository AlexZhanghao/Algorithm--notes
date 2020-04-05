#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

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
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		stack<double> lower;
		stack<double> upper;
		s.push(root);
		lower.push(0.1);
		upper.push(0.1);
		while (!s.empty()) {
			TreeNode* cur = s.top();
			double l = lower.top();
			double u = upper.top();
			s.pop();
			lower.pop();
            upper.pop();
			if (cur == NULL) continue;
			if (l != 0.1 && l >= cur->val) return false;
			if (u != 0.1 && u <= cur->val) return false;
			if (cur->left != NULL) {
				TreeNode* lnext = cur->left;
				s.push(lnext);
				lower.push(l);
				upper.push(cur->val);
			}
			if (cur->right != NULL) {
				TreeNode* rnext = cur->right;
				s.push(rnext);
				lower.push(cur->val);
				upper.push(u);
			}
		}
		return true;
	}
};