#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class WordsFrequency {
public:
    WordsFrequency(vector<string>& book) {
        int n=book.size();
        for(int i=0;i<n;++i) ++m[book[i]];
    }
    
    int get(string word) {
        return m[word];
    }

private:
    unordered_map<string,int> m;
};