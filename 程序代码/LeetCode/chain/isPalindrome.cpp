#include<iostream> 

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//要求用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题
//这里我先遍历一遍链表，记录下个数，然后除二取中间值，
//找中间节点这里可以用快慢指针进行优化，一个指针走两边，一个指针走一步。
//然后从中间节点开始，往后反转链表，反转完成后再和前半部分进行比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        ListNode* prev=NULL,*cur=mid,*nex=mid;
        while(cur->next){
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        cur->next=prev;
        while(cur){
            if(cur->val!=head->val) return false;
            cur=cur->next;
            head=head->next;
        }
        return true;
    }
};