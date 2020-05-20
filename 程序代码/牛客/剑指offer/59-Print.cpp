#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//写代码时，要仔细再仔细，尤其复制一段代码到另一个位置的时候
class Solution {
public:
    vector<vector<int>> Print(TreeNode* pRoot) {
        if(pRoot==NULL) return {};
        stack<TreeNode*> ltor,rtol;
        ltor.push(pRoot);
        vector<vector<int>> out;
        while(!ltor.empty()||!rtol.empty()){
            vector<int> mid;
            while(!ltor.empty()){
                TreeNode *cur=ltor.top();
                ltor.pop();
                mid.push_back(cur->val);
                if(cur->left!=NULL) rtol.push(cur->left);
                if(cur->right!=NULL) rtol.push(cur->right);
            }
            if(!mid.empty()){
                out.push_back(mid);
                mid.clear();
            }

            while(!rtol.empty()){
                TreeNode *cur=rtol.top();
                rtol.pop();
                mid.push_back(cur->val);
                if(cur->right!=NULL) ltor.push(cur->right);
                if(cur->left!=NULL) ltor.push(cur->left);
            }
            if(!mid.empty()) out.push_back(mid);
        }
        return out;
    }   
};
