#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()<5) return false;
        sort(numbers.begin(),numbers.end());
        int count=0,dif=0;
        for(int i=0;i<numbers.size();++i){
            if(numbers[i]==0) ++count;
            else if(i>0&&numbers[i]==numbers[i-1]) return false;
        }
        int j=count;
        while(j<numbers.size()-1){
            dif=numbers[j+1]-numbers[j];
            if(dif>1){
                --dif;
                if(dif>count) return false;
                else count-=dif;
            }
            ++j;
        }
        return true;
    }
};