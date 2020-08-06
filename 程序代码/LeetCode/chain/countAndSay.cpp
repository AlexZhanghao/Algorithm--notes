#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev="1";
        for(int i=1;i<n;++i){
            string next="";
            char pos=prev[0];
            int count=0;
            for(int j=0;j<prev.size();++j){
                if(prev[j]==pos) ++count;
                else{
                    next+=to_string(count);
                    next+=pos;
                    pos=prev[j];
                    count=1;
                }
            }
            next+=to_string(count);
            next+=pos;
            prev=next;
        }
        return prev;
    }
};