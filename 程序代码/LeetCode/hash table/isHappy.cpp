#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n<1) return false;
        if(n==1) return true;
        unordered_set<int> book;
        while(n>1){
            vector<int> v;
            while(n>0){
                v.push_back(n%10);
                n/=10;
            }
            for(int i=0;i<v.size();++i){
                n+=v[i]*v[i];
            }
            if(book.count(n)) return false;
            else book.insert(n);
        }
        return true;
    }
};