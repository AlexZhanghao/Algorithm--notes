#include<iostream>
#include<vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* start,* end;
        start=head;
        end=head;
        for(int i=0;i<k-1;++i){
            end=end->next;
        }
        while(end->next!=NULL){
            start=start->next;
            end=end->next;
        }

        return start;
    }
};