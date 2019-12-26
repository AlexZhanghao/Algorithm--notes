//Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 struct Queue{
     int data[10];
     int front;
     int rear;
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    }

    void InitQueue(Queue *Q){
        Q->rear=0;
        Q->rear=0;
    }

    void Enqueue(Queue Q,int x){
    }
};