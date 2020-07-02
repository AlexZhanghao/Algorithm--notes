#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};

vector<int> preorder(TreeNode* root){
    if(root==NULL) return {};
    TreeNode* ptr=root;
    stack<TreeNode*> s;
    vector<int> out;
    while(ptr){
        while(ptr){
            out.push_back(ptr->val);
            if(ptr->right) s.push(ptr->right);
            ptr=ptr->left;
        }
        
        if(!s.empty()){
            ptr=s.top();
            s.pop();
        }
    }
    return out;
}

vector<int> inorder(TreeNode* root){
    if(root==NULL) return {};
    TreeNode* ptr=root;
    stack<TreeNode*> s;
    vector<int> out;
    while(ptr||!s.empty()){
        while(ptr){
            s.push(ptr);
            ptr=ptr->left;
        }

        ptr=s.top();
        s.pop();
        out.push_back(ptr->val);
        ptr=ptr->right;
    }
    return out;
}

//这里采用先“根->右->左”的遍历，然后在反转的处理
vector<int> postorder(TreeNode* root) {
	if (root == NULL) return {};
	TreeNode* ptr = root;
	stack<TreeNode*> s;
	vector<int> out;
	while (ptr) {
		while (ptr) {
			out.push_back(ptr->val);
			if(ptr->left)s.push(ptr->left);
			ptr = ptr->right;
		}

		if (!s.empty()) {
			ptr = s.top();
			s.pop();
		}
	}
	reverse(out.begin(), out.end());
	return out;
}

int main(){
    TreeNode* root=new TreeNode(1);
    TreeNode* ptr1=root,* ptr2=root;
    ptr1->left=new TreeNode(2);
    ptr1=ptr1->left;
    ptr1->right=new TreeNode(4);
    ptr2->right=new TreeNode(3);
    ptr2=ptr2->right;
    ptr2->left=new TreeNode(5);
    vector<int> out=postorder(root);
    for(int i=0;i<out.size();++i){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return 0;
}