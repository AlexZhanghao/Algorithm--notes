#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//迭代
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		ListNode* ptr1 = pHead1, *ptr2 = pHead2, *ptr, *head;
		head = new ListNode(0);		
		ptr = head->next;
		while (ptr1 != NULL && ptr2 != NULL) {
			if (ptr1->val >= ptr2->val) {
				ptr = new ListNode(ptr2->val);
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}
			else {
				ptr = new ListNode(ptr1->val);
				ptr = ptr->next;
				ptr1 = ptr1->next;
			}
		}
		if (ptr1 != NULL && ptr2 == NULL) {
			ptr = ptr1;
		}
		else if (ptr1 == NULL && ptr2 != NULL) {
			ptr = ptr2;
		}
		return head->next;
	}
};

//递归
class Solution2 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
       else if(pHead2==NULL)
            return pHead1;
         
         ListNode* newhead=NULL;
        
        if(pHead1->val<pHead2->val)
                 
           {
              newhead=pHead1;
              newhead->next=Merge(pHead1->next,pHead2);
          }
           else
               {
               newhead=pHead2;
              newhead->next=Merge(pHead1,pHead2->next);
           }
       return newhead;
    }
};
