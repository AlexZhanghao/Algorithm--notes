#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		//当链表长度为1的时候结束递归
		if (head == NULL || head->next == NULL) return head;

        //分割链表
        ListNode* fast = head, *slow = head;
		while (fast->next&&fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* tmp = slow->next;
		slow->next = NULL;

        //将分割后的左右链表递归
		ListNode* left = sortList(head);
		ListNode* right = sortList(tmp);

		//将左右链表合并
		ListNode* l = left, *r = right;
		ListNode* prev = new ListNode(-1);
		ListNode* ptr = prev;
		while (l&&r) {
			if (l->val <= r->val) {
				ptr->next = l;
				if (ptr->next) ptr = ptr->next;
				l = l->next;
			}
			else {
				ptr->next = r;
				if (ptr->next) ptr = ptr->next;
				r = r->next;
			}
		}

		if (l) ptr->next = l;
		if (r) ptr->next = r;
		return prev->next;
	}
};