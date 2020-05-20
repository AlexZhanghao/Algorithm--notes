#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==NULL) return pHead;
		ListNode *prv=NULL,*cur=pHead,*nex=pHead;
		while(cur->next!=NULL){
			nex=cur->next;
			cur->next=prv;
			//注意这里下一步不能要，不然下次循环时nex就成了prv
			//nex->next=cur;
			prv=cur;
			cur=nex;
		}
		cur->next=prv;
		return cur;
    }
};