#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==0){
            return 0;
        }

        unordered_map<char,int> con;
        int longestsize=0;
        int count_1=0;
        for(int i=0;i<s.size();++i){
            if(con.find(s[i])!=con.end()){
                ++con[s[i]];
            }
            else{
                con[s[i]]=1;
            }
        }

        for(auto ite=con.begin();ite!=con.end();++ite){
           int a=(*ite).second;
           if(a%2==0){
               longestsize+=a;
           }else{     
               count_1=1;          
               longestsize+=(a-1);
           }           
        }
        if(count_1==1) ++longestsize;

        return longestsize;
    }
};


class Solution2 {
public:
int longestPalindrome(string s)
{
    int c[128]={0},ret=0;
    int ssize=s.size();
    
    for(int i=0;i<ssize;i++)
    {
        c[s[i]]++;
    }

    for(int i=0;i<128;i++)
    {
        ret+=c[i]-c[i]%2;
    }


    return ret+(ret!=ssize);
}
};

