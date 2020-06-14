#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *prev=head,*start=head,*end;
        while(start){
           if(start) end=start->next;
           if(end&&start->val==end->val){
               while(end&&start->val==end->val) end=end->next;
               if(prev==start){
                   prev=end;
               }
               else{
                   prev->next=end;
               }
               start=end;
           }
           else{
               if(start==prev) start=end;
               else{
                   prev=start;
                   start=end;
               }
           }
        }
        return head;
    }
};