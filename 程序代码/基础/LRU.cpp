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