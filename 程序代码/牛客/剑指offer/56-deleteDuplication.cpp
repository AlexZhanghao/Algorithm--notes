#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead==NULL) return pHead;        
        while(pHead!=NULL&&pHead->next!=NULL&&pHead->next->val==pHead->val){ 
            int startval=pHead->val;           
            while(pHead!=NULL&&pHead->val==startval) pHead=pHead->next;
        }
        ListNode* begin=pHead,*start=pHead,*end;
        while(begin!=NULL){
            start=begin->next;
            if(start!=NULL){
                if(start->next!=NULL&&start->val==start->next->val){
                    end=start->next;
                    while(end!=NULL&&end->val==start->val) end=end->next;
                    begin->next=end;
                }
                else begin=start;
            }
            else begin=start;
        }
        return pHead;
    }
};