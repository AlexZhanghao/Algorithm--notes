#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

//环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        unordered_set<ListNode*> s;
        while(head){
            if(s.count(head)){
                return true;
            }
            s.insert(head);
            head=head->next;
        }
        return false;
    }
};

//环形链表II
class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return false;
        unordered_set<ListNode*> s;
        while(head){
            if(s.count(head)){
                return head;
            }
            s.insert(head);
            head=head->next;
        }
        return NULL;
    }
};

//环形链表II--双指针解法
//https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
class Solution3 {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return NULL;
        ListNode *fast=head,*slow=head;
        while(true){
            //快指针每次前进两步
            if(fast) fast=fast->next;
            else return NULL;
            if(fast) fast=fast->next;
            else return NULL;
            
            //慢指针每次前进一步
            slow=slow->next;

            //检查快指针追上了慢指针
            if(fast==slow) break;
        }

        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }

        return fast;
    }
};