#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int ssize=s.size();
        if(ssize==0) return true;
        int start=0;
        bool is_pot=false,is_e=false;
        for(int i=0;i<ssize;++i){
            if(s[0]!=' '){
                start=i;
                break;
            }
        }
        if(ssize-start==1&&!Isnum(s[start])) return false;
        if(Isnum(s[start])||s[start]=='+'||s[start]=='-') {}
        else if(s[start]=='.') is_pot=true;
        else return false;
        ++start;
        for(start;start<ssize;++start){
            if(Isnum(s[start])) continue;
            else if(s[start]=='.'){
                if(is_pot) return false;
                else is_pot=true;                   
            }
            else if(s[start]='e'){
                if(is_e) return false;
                else is_e=true;
            }
            else return false;
        }

        return true;
    }

    bool Isnum(char a){
        return a>47&&a<58;
    }
};

//奇淫巧技之"有限状态机"
class Solution {
public:
    bool isNumber(string s) {
        int ssize=s.size();
         vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // 合法的终止状态
        vector<vector<int> > transfer({
            {0,  1,  6,  2,  -1, -1},
            {-1, -1, 6,  2,  -1, -1},
            {-1, -1, 3,  -1, -1, -1},
            {8,  -1, 3,  -1, 4,  -1},
            {-1, 7,  5,  -1, -1, -1},
            {8,  -1, 5,  -1, -1, -1},
            {8,  -1, 6,  3,  4,  -1},
            {-1, -1, 5,  -1, -1, -1},
            {8,  -1, -1, -1, -1, -1},
        });
        int state=0;
        for(int i=0;i<ssize;++i){
            int j=0;        
            switch(s[i]){
                case ' ':
                    j=0;
                    break;
                case '+':
                    j=1;
                    break;
                case '-':
                    j=1;
                    break;
                case '.':
                    j=3;
                    break;
                case 'e':
                    j=4;
                    break;
                default:
                    if(s[i]>47&&s[i]<58) j=2;
                    else j=5;
            }
            state=transfer[state][j];
            if(state==-1) return false;
        }

        return finals[state];
    }
};