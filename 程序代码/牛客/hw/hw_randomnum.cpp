#include<iostream>
#include<set>

using namespace std;

int main(){
    string num[1000];
    int n=0;
    while(cin>>n){
        set<int> s;
        for(int i=0;i<n;++i){
            int num;
            cin>>num;
            s.insert(num);
        }
        auto ite1=s.begin();
        auto ite2=s.end();
        for(;ite1!=ite2;++ite1){
            cout<<*ite1<<endl;
        }
    }
    return 0;
}