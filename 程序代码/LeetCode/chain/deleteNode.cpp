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
    ListNode* deleteNode(ListNode* head, int val) {        
        ListNode *prev=head;
        ListNode *cur=head;
        if(head->val==val){
            head=head->next;
            return head;
        }
        cur=head->next;
        while(cur->val!=val&&cur->next!=NULL){
            prev=cur;
            cur=cur->next;
        }
        prev->next=cur->next;
        return head;
    }
};