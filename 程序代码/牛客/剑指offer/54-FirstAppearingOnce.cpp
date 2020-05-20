#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    void Insert(char ch){
        strstream+=ch;
    }

    //两次遍历
    char FirstAppearingOnce(){
        int ssize=strstream.size();
        if(ssize==0) return '#';
        char firstchar='#';
        
        for(int i=cur;i<ssize;++i){
            ++m[strstream[i]];
        }
        cur=ssize;

        for(int j=firstpos;j<ssize;++j){
            if(m[strstream[j]]==1){
                firstchar=strstream[j];
                firstpos=j;
                break;
            }
        }
        return firstchar;        
    }

private:
    string strstream;
    int cur=0,firstpos=0;
    unordered_map<int,int> m;
};