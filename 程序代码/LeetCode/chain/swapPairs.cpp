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
        ListNode* slow=head,*fast=head->next;
        ListNode* prev;
        //因为最开始的两个节点换位后还得把head重定位一下，所以第一次交换应当单独拿出来
        if(fast!=NULL){
            slow->next=fast->next;
            fast->next=slow;
            head=fast;
            prev=slow;
            slow=slow->next;
            //注意检查
            if(slow) fast=slow->next;
            else fast=NULL;
        }
        while(fast!=NULL){
            slow->next=fast->next;
            fast->next=slow;
            prev->next=fast;
            prev=slow;
            slow=slow->next;
            //注意检查
            if(slow) fast=slow->next;
            else fast=NULL;
        }
        return head;
    }
};