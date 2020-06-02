#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10) return{};
        unordered_set<string> hash_s,hashed;
        vector<string> out;
        for(int i=0;i<n-9;++i){
            string a=s.substr(i,10);
            cout<<a<<endl;
            if(hash_s.count(a)){
                if(hashed.count(a)) continue;
                else{
                    out.push_back(a);
                    hashed.insert(a);
                }
            }
            else{
                hash_s.insert(a);               
            }
        }
        return out;
    }
};