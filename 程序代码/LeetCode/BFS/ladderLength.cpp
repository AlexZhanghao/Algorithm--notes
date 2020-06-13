#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //s保存wordList中所有的字符
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.empty()||!s.count(endWord)) return 0;
        s.erase(beginWord);

        //q保存当前进行到的字符
        queue<string> q;
        q.push(beginWord);

        //al保存已经使用过的字符
        unordered_set<string> al;
        al.insert(beginWord);

        int wordlen=beginWord.size();
        int step=1;
        while(!q.empty()){

            int qsize=q.size();
            
            for(int i=0;i<qsize;++i){
                string cur=q.front();
                q.pop();

                for(int j=0;j<wordlen;++j){
                    char need_change=cur[j];
                    for(char k='a';k<='z';++k){
                        if(k==need_change) continue;

                        string nextword=cur;
                        nextword[j]=k;

                        if(s.count(nextword)){
                            if(nextword==endWord) return step+1;

                            if(!al.count(nextword)){
                                q.push(nextword);
                                al.insert(nextword);
                            }
                        }
                    }
                }
            }
            ++step;
        }

        return 0;
    }
};