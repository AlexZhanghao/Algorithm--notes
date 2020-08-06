#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        else if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        for(int i=1;i<lists.size();++i){
            mergeTwoLists(lists[0],lists[i]);
        }

        return lists[0];
    }
};

// 小根堆的回调函数
struct cmp{  
    bool operator()(ListNode *a,ListNode *b){
        //大的下移
        return a->val > b->val;
    }
};

//优先队列
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode* prev=new ListNode(-1);
        ListNode* ptr=prev;
        
        for(int i=0;i<n;++i){
            if(lists[i]) pq.push(lists[i]);
        }

        while(!pq.empty()){
            ListNode* cur=pq.top();
            pq.pop();
            ptr->next=cur;
            ptr=ptr->next;
            if(cur->next) pq.push(cur->next);
        }

         return prev->next;
    }
};