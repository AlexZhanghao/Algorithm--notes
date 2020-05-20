#include<iostream>
#include<vector>
#include<algorithm>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        if(pHead==NULL) return NULL;
        unordered_set<ListNode*> us;
        while(pHead!=NULL){
            if(pHead->next==NULL) return NULL;
            if(us.count(pHead)) return pHead;
            us.insert(pHead);
            pHead=pHead->next;
        }
        return NULL;
    }
};