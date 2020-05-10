#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,int> m_num;
        unordered_map<char,int> m_pos;
        for(int i=0;i<str.size();++i){
            ++m_num[str[i]];
            m_pos[str[i]]=i;
        }
        int pos=99999;
        for(auto j=m_num.begin();j!=m_num.end();++j){
            if(j->second==1){
                pos=pos>(m_pos[j->first])?m_pos[j->first]:pos;
            }
        }
        return pos==99999?-1:pos;
    }
};