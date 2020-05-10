#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        unordered_map<RandomListNode*,RandomListNode*> hm;
        for(RandomListNode* i=pHead;i!=NULL;i=i->next){
            hm[i]=new RandomListNode(i->label);
        }

        for(RandomListNode *i=pHead;i!=NULL;i=i->next){
            if(i->next!=NULL) hm[i]->next=hm[i->next];
            if(i->random!=NULL) hm[i]->random=hm[i->random];
        }

        return hm[pHead];
    }
};

struct Node {
    int val;
    struct Node *next, *random;
    Node(int x) :
            val(x), next(NULL), random(NULL) {
    }
};

//力扣上一个老哥的DFS解法
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> used;
        return dfs(head, used);
    }
    
    Node* dfs(Node* head, unordered_map<Node*, Node*>& used) {
        if (!head) return nullptr;
        if (used.count(head)) return used[head];
        Node *res = new Node(head->val);
        used[head] = res;
        res->next = dfs(head->next, used);
        res->random = dfs(head->random, used);    
        return res;
    }
};

//BFS解法
class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        return bfs(head);
    }
    
    Node* bfs(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> used;
        used[head] = new Node(head->val);
        queue<Node*> q;
        q.push(head);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node *t = q.front(); q.pop();
                if (t->next) {
                    if (!used[t->next]) {
                        used[t->next] = new Node(t->next->val);
                        q.push(t->next);
                    }
                    used[t]->next = used[t->next];
                }
                if (t->random) {
                    if (!used[t->random]) {
                        used[t->random] = new Node(t->random->val);
                        q.push(t->random);
                    }
                    used[t]->random = used[t->random];
                }
            }
        }
        return used[head];
    }
};