#include<iostream>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr) return pHead;
        ListNode* prev=NULL,*cur=pHead,*nex=pHead;
        while(cur->next!=NULL){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        cur->next=prev;
        return cur;
    }
};