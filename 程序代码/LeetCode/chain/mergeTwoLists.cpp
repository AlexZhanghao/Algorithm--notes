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

//迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l2->val<l1->val){
            swap(l1,l2);
        }
        
        ListNode* root=l1;
        while(root!=nullptr&&l2!=nullptr){
            while(root->next&&root->next->val<=l2->val) root=root->next;
            ListNode* a=root->next;
            root->next=l2;
            if(l2)l2=l2->next;
            root=root->next;

            if(root)root->next=a;
            else root=a;
        }
        return l1;
    }
};
//递归
class Solution2 {
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
};