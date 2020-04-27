#include <iostream>
#include <unordered_set>
#include<vector>

using namespace std;

int main() {
    int n,m,f;
    while(cin>>n>>m>>f){
        unordered_set<int> s;
        s.insert(f);
        for(int i=0;i<m;++i){
            int q;
            cin>>q;
            vector<int> cnt(q,0);
            bool is_find=false;
            for(int j=0;j<q;++j){
                int k;
                cin>>k;
                cnt[j]=k;
                auto ite1=s.find(k);
                if(ite1!=s.end()) is_find=true;
            }
            if(is_find){
                for(int k=0;k<q;++k){
                    s.insert(cnt[k]);
                }
            }
        }
        printf("%d\n",s.size());
    }
    return 0;
}