#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==NULL||pRoot2==NULL) return false;
        return IsSubtree(pRoot1,pRoot2);
    }

    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot1==NULL) return false;
        if(pRoot1->val==pRoot2->val){
            if(Compare(pRoot1,pRoot2)) return true;
        }
        if(IsSubtree(pRoot1->left,pRoot2)||IsSubtree(pRoot1->right,pRoot2)) return true;
        return false;
    }

    bool Compare(TreeNode* pRoot1, TreeNode* pRoot2){
        //这里需要注意，即使pRoot1不为空也可以返回，因为这里要求pRoot2是pRoot1的子结构，而不是要求他们完全相同
        if(pRoot2==NULL) return true;
        if(pRoot1==NULL||pRoot1->val!=pRoot2->val) return false;
        if(!Compare(pRoot1->left,pRoot2->left)||!Compare(pRoot1->right,pRoot2->right)) return false;
        return true;
    }
};