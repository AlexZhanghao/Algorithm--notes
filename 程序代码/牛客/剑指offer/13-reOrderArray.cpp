#include<iostream>
#include<vector>

using namespace std;

//这里运用了冒泡算法的思想，这里除非i及以后全是奇数或者偶数，否则只要i后有奇数，就肯定可以慢慢置换到i来
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i=0;i<array.size();++i){
            for(int j=array.size()-1;j>i;--j){
                if(array[j]%2==1&&array[j-1]%2==0) swap(array[j],array[j-1]);
            }
        }
    }
};