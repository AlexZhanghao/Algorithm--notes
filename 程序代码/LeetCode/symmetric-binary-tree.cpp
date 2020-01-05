#include <iostream>

using namespace std;

#define queue_length 10000

//Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct Queue{
     TreeNode* data[queue_length];
     int front;
     int rear;
 }q;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }

    bool isMirror(TreeNode *root1,TreeNode *root2){
        if(root1==NULL&&root2==NULL){
            return true;
        }
        if(root1==NULL||root2==NULL){
            return false;
        }

        InitQueue(q);
        Enqueue(q,root1);
        Enqueue(q,root2);
        while(q.front!=q.rear){
            int queue_start=q.front;
            int queue_end=q.rear;
            for(int i=queue_start;i<queue_end;i+=2){
					if (q.data[i]->val != q.data[i + 1]->val) {
						return false;
					}
					// if (q.data[i]->left == NULL && q.data[i + 1]->right != NULL || q.data[i]->left != NULL && q.data[i + 1]->right == NULL ||
					// 	q.data[i]->right == NULL && q.data[i + 1]->left != NULL || q.data[i]->right != NULL && q.data[i + 1]->left == NULL) {
					// 	return false;
					// }
					if (q.data[i]->left != NULL && q.data[i + 1]->right != NULL) {
						Enqueue(q, q.data[i]->left);
						Enqueue(q, q.data[i + 1]->right);
					}
					if (q.data[i]->right != NULL && q.data[i + 1]->left != NULL) {
						Enqueue(q, q.data[i]->right);
						Enqueue(q, q.data[i + 1]->left);
					}
					Dequeue(q);
					Dequeue(q);

            }
        }
        return true;
    }

    void InitQueue(Queue &Q){
        Q.front=0;
        Q.rear=0;
    }

    bool Enqueue(Queue &Q,TreeNode *x){
        if (x == NULL) {
			return false;
		}
        if(Q.rear+1==Q.front){
            return false;
        }
        Q.data[Q.rear]=x;
        if(Q.rear!=queue_length-1){
            ++Q.rear;
        }else{
            Q.rear=0;
        }
        return true;
    }

    bool Dequeue(Queue &Q){
        if(Q.front==Q.rear){
            return false;
        }
        Q.data[Q.front]=NULL;
        if(Q.front!=queue_length-1){
            ++Q.front;
        }else{
            Q.front=0;
        }
        return true;
    }

    bool IsQueueEmpty(Queue Q){
        return Q.front==Q.rear;
    }
};