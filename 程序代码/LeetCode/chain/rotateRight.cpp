#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) return nullptr;
        
		ListNode* a, *b, *end;
		a = head;
		int sum = 1, count = 1;
		while (a->next != NULL) {
			++sum;
			a = a->next;
		}
		end = a; a = head;
		if(k>sum)k = k % sum;
		else if (k == sum) return head;
        if(k==0) return head;
		count = sum - k;

		while (count > 1) {
			a = a->next;
			--count;
		}

		b = a;
		a = a->next;
		b->next = NULL;
		end->next = head;
		head = a;

		return head;
	}
};