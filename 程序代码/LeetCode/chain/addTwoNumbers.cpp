#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

//两数相加I
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* prev = new ListNode(-1);
		ListNode* ptr=prev;
		int a = 0, on = 0;
		while (l1 || l2) {
            ptr->next=new ListNode(0);
            ptr=ptr->next;
			if (l1 == NULL) {
				l1 = new ListNode(0);
				a = (l1->val + l2->val + on) % 10;
				on = (l1->val + l2->val + on) / 10;
				ptr->val = a;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l2 == NULL) {
				l2 = new ListNode(0);
				a = (l1->val + l2->val + on) % 10;
				on = (l1->val + l2->val + on) / 10;
				ptr->val = a;
				l1 = l1->next;
				l2 = l2->next;
			}
			else {
				a = (l1->val + l2->val + on) % 10;
				on = (l1->val + l2->val + on) / 10;
				ptr->val = a;
				l1 = l1->next;
				l2 = l2->next;
			}
		}

		if (on) {
			ptr->next=new ListNode(1);
		}
		return prev->next;
	}
};

//两数相加II
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }

        
        int a=0,is_on=0;
        ListNode* prev=new ListNode(-1);
        while(!s1.empty()&&!s2.empty()){
            a=(s1.top()+s2.top()+is_on)%10;
            is_on=(s1.top()+s2.top()+is_on)/10;
            s1.pop();s2.pop();
            ListNode* l=new ListNode(a);
            l->next=prev->next;
            prev->next=l;
        }

        if(!s1.empty()){
            while(!s1.empty()){
                a=(s1.top()+is_on)%10;
                is_on=(s1.top()+is_on)/10;
                s1.pop();
                ListNode* l=new ListNode(a);
                l->next=prev->next;
                prev->next=l;
            }
        }
        else if(!s2.empty()){
            while(!s2.empty()){
                a=(s2.top()+is_on)%10;   
                is_on=(s2.top()+is_on)/10;
                s2.pop();
                ListNode* l=new ListNode(a);
                l->next=prev->next;
                prev->next=l;
            }
        }

        if(is_on){
            ListNode* l=new ListNode(1);
            l->next=prev->next;
            prev->next=l;
        }
        return prev->next;
    }
};