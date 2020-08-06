#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        pair<int,int> itr=*m[key];
        l.erase(m[key]);
        l.push_front(itr);
        m[key]=l.begin();
        return itr.second;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            l.erase(m[key]);
            l.push_front(make_pair(key,value));
            m[key]=l.begin();
        }
        else{
            if(l.size()>=cap){
                auto last=l.back();
                m.erase(last.first);
                l.pop_back();
            }
            l.push_front(make_pair(key,value));
            m[key]=l.begin();
        }
    }

private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
};

int main(){
    LRUCache* cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    cout<<cache->get(1);       // 返回  1
    cache->put(3, 3);          // 该操作会使得关键字 2 作废
    cout<<cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);          // 该操作会使得关键字 1 作废
    cout<<cache->get(1);       // 返回 -1 (未找到)
    cout<<cache->get(3);       // 返回  3
    cout<<cache->get(4);       // 返回  4

}