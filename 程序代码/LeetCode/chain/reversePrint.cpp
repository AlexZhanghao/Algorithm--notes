#include<iostream>
#include<vector>
#include<stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> v;
        while(head!=NULL){
            s.push(head->val);
            head=head->next;
        }
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

//这个老哥用的递归也有点味道
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};