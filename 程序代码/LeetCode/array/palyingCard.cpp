// 我手中有一堆扑克牌， 但是观众不知道它的顺序。

// 1、第一步， 我从牌顶拿出一张牌， 放到桌子上。
// 2、第二步， 我从牌顶再拿一张牌， 放在手上牌的底部。
// 3、第三步， 重复第一步、第二步的操作， 直到我手中所有的牌都放到了桌子上。

// 最后， 可以看到桌子上牌的顺序是：(牌底部）1,2,3,4,5,6,7,8,9,10,11,12,13(牌顶部）
// 问， 刚开始拿在手里的牌的顺序是什么？

#include<iostream>
#include<vector>
#include<list>

using namespace std;

vector<int> MovePlayingcard(vector<int> &cards){
    int n=cards.size();

    vector<int> ret;
    list<int> l;
    int pos=n-1;
    while(pos>=0){
        if(l.size()>0){
            int cur=l.back();
            l.pop_back();
            l.push_front(cur);
        }

        l.push_front(cards[pos]);
        --pos;
    }

    for(auto i=l.begin();i!=l.end();++i){
        ret.push_back(*i);
    }

    return ret;
}

int main(){
    vector<int> a={1,2,3,4,5,6,7,8,9,10,11,12,13};
    vector<int> b=MovePlayingcard(a);
    for(int i=0;i<b.size();++i){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}