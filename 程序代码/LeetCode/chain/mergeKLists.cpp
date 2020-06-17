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
        return a->val > b->val;
    }
};

//优先队列
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
};