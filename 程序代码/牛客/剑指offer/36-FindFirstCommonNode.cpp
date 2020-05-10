#include<iostream>
#include<vector>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_set<ListNode*> ls;
        while(pHead1!=NULL){
            ls.insert(pHead1);
            pHead1=pHead1->next;
        }
        while(pHead2!=NULL){
            if(ls.count(pHead2)) break;
            pHead2=pHead2->next;
        }

        return pHead2;
    }
};

//很神奇的力扣老哥解法（注意：这里在双双互换一次后，必定会相遇。）
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* Astart=headA,*Bstart=headB;
        while(headA!=headB){
            headA=(headA==NULL)?Bstart:headA->next;
            headB=(headB==NULL)?Astart:headB->next;
        }

        return headB;
    }
};