#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int half=numbers.size()/2;
        unordered_map<int,int> book;
        for(int i=0;i<numbers.size();++i){
            ++book[numbers[i]];
            if(book[numbers[i]]>half) return numbers[i];
        }
        return 0;
    }
};