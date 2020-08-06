#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* merge(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	if (head1->val <= head2->val) {
		head1->next = merge(head1->next, head2);
		return head1;
	}
	else {
		head2->next = merge(head1, head2->next);
		return head2;
	}
}

//链表奇数位升序，偶数位降序，如何改为有序链表
ListNode* Listorder(ListNode* head) {
	bool is_odd = true;
	ListNode* oddprev = new ListNode(-1);
	ListNode* evenprev = new ListNode(-1);
	ListNode* ptr = head, *oddptr = oddprev, *evenptr = evenprev;
	//将奇偶分离
	while (ptr) {
		ListNode* a = ptr;
		ptr = ptr->next;
		if (is_odd) {
			oddptr->next = a;
			oddptr = oddptr->next;
			oddptr->next = NULL;
			is_odd = false;
		}
		else {
			evenptr->next = a;
			evenptr = evenptr->next;
			evenptr->next = NULL;
			is_odd = true;
		}
	}

	//将偶数链表翻转
	ListNode* prev = NULL, *cur = evenprev->next, *nex = evenprev->next;
	while (cur->next) {
		nex = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nex;
	}
	cur->next = prev;

	//将奇偶链表合并
	ptr = oddprev->next;
	return merge(cur, ptr);
}

int main() {
	ListNode* a = new ListNode(-1);
	ListNode* ptr = a;
	int n;
	cin >> n;
	while (n--) {
		int b;
		cin >> b;
		ptr->next = new ListNode(b);
		ptr = ptr->next;
	}
	a = a->next;
	ptr = Listorder(a);
	while (ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	getchar(); getchar();
	return 0;
}