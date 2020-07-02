#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* left=head,*right=head->next,* pre=prev;
        while(right){
            pre->next=right;
            left->next=right->next;
            right->next=left;
            pre=left;
            left=left->next;
            if(left) right=left->next;
            else right=NULL;
        }
        return prev->next;
    }
};