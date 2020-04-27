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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head,*prev=NULL,*nex=NULL;
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