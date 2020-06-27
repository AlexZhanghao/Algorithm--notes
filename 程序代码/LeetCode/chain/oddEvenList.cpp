#include<iostream> 

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

//要求用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        bool is_odd=true;
        ListNode* ptr=head->next->next,*oddptr=head,*evenptr=head->next;
        while(ptr){
            ListNode* a=ptr;
            ptr=ptr->next;
            if(is_odd){
                a->next=oddptr->next;
                oddptr->next=a;
                oddptr=oddptr->next;
                is_odd=false;
            }
            else{
                a->next=evenptr->next;
                evenptr->next=a;
                evenptr=evenptr->next;
                is_odd=true;
            }
        }
        evenptr->next=NULL;
        return head;
    }
};