#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<vector<int>> v;
        for(int i=0;i<n;++i){
            int k;
            cin>>k;
            vector<int> mid(k,0);
            int num=0;
            for(int j=0;j<k;++j){
                cin>>mid[j];
                num+=mid[j];
            }
            mid.push_back(num);
            v.push_back(mid);
        }
        
        for(int i=0;i<v.size();++i){
            bool is_change=false;
            for(int j=0;j<v.size();++j){
                if(is_change) break;                
                if(j==i) continue;
                if(v[j].back()>v[i].back()){
                    int down=v[j].back()-v[i].back();
                    for(int k=1;k<v[j].size()-1;++k){
                        if(v[j][k]==down) v[j].back()=v[i].back();
                        is_change=true;
                    }
                }
            }
        }

        int max_count=0;
        for(int i=0;i<v.size();++i){
            int count=0;
            for(int j=0;j<v.size();++j){
                if(v[i].back()==v[j].back()) ++count;
            }
            if(max_count<count) max_count=count;
        }
        cout<<max_count<<endl;
    }
}