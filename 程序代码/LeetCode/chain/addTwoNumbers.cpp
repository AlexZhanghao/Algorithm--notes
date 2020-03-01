#include<iostream>
#include<vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution_error {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }

        bool carry=false;
        ListNode *lsum=new ListNode(0);
        ListNode *start=lsum;
        int sum=0;
        int remainder=0;

        while(l1!=NULL&&l2!=NULL){
            if(carry){
                sum=l1->val+l2->val+1;
            }else{
                sum=l1->val+l2->val;
            }
            carry=(sum/10==0?0:1);
            remainder=sum%10;
            lsum->val=remainder;            
            lsum=lsum->next;
            lsum=new ListNode(0);
            l1=l1->next;
            l2=l2->next;
        }

        if(carry){
            if(l1==NULL&&l2!=NULL){
                if(l2->val!=9){
                    ++l2->val;
                    lsum->val=l2->val;
                    l2=l2->next;
                    lsum=lsum->next;
                }else{
                    lsum=lsum->next;
                    l2=l2->next;
                    lsum=new ListNode(++l2->val);
                    lsum=lsum->next;
                    l2=l2->next;
                }
                while(l2!=NULL){
                    lsum=new ListNode(0);
                    lsum->val=l2->val;
                    lsum=lsum->next;
                    l2=l2->next;
                }                            
            }
            else if(l1!=NULL&&l2==NULL){
                if(l1->val!=9){
                    ++l1->val;
                    lsum->val=l1->val;
                    l1=l1->next;
                    lsum=lsum->next;
                }else{
                    lsum=lsum->next;
                    l1=l1->next;
                    lsum=new ListNode(++l1->val);
                    lsum=lsum->next;
                    l1=l1->next;
                }
                while(l1!=NULL){
                    lsum=new ListNode(0);
                    lsum->val=l1->val;
                    lsum=lsum->next;
                    l1=l1->next;
                }   
            }
            else{
                lsum->next=new ListNode(1);
                lsum=lsum->next;
            }
        }

        return start;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int remainder=0;       
        ListNode *start=new ListNode(0);
        ListNode *temsum=start;
        while(l1||l2||carry){
            int mednum=0;
            if(l1){
                mednum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                mednum+=l2->val;
                l2=l2->next;
            }
            if(carry){
                mednum+=carry;
                --carry;
            }

            remainder=mednum%10;
            carry=mednum/10;
            temsum->next=new ListNode(remainder);
            temsum=temsum->next;
        }
        temsum=start->next;
        delete start;
        return temsum;
    }
};