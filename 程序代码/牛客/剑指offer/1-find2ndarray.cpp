#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row=array.size();
        int cloumn=array[0].size();
        int i=row-1,j=0;
        while(i>=0&&j<cloumn){
            if(array[i][j]>target) --i;
            else if (array[i][j]<target) ++j;
            else return true;
        }

        return false;
    }
};