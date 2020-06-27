#include<iostream> 
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(root==NULL) return  vector<ListNode*>(k,NULL);
        int count=0;
        ListNode* ptr=root;
        while(ptr){
            ++count;
            ptr=ptr->next;
        }
        int a=count/k;
        int b=count%k;
        int c = k > count ? (k - b) : ((count -b)/a - b);
        ptr=root;

        vector<ListNode*> out;
        //这里其实可以将b和c放在一起算
        while(b--){
            ListNode* start=ptr;
            int j=a;
            while(j--) ptr=ptr->next;
            ListNode* end=ptr;
            ptr=ptr->next;
            end->next=NULL;
            out.push_back(start);
        }

        if(a==0){
            while(c--) out.push_back({});
        }else{
            --a;
            while(c--){
                ListNode* start=ptr;
                int j=a;
                while(j--) ptr=ptr->next;
                ListNode* end=ptr;
                ptr=ptr->next;
                end->next=NULL;
                out.push_back(start);
            }
        }

        return out;
    }
};