#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

struct node{
    node*  next;
    int val;
};

class hashtable{
public:
    hashtable(){
    }
private:
    vector<node*> buckets;
    int hashnum=193;
};

int main(){
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=0;i<10;++i) pq.push(i);
    cout<<pq.top()<<endl;
    return 0;
}