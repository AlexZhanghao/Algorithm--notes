#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length<2) return false;
        unordered_set<int> s;
        for(int i=0;i<length;++i){
            if(s.count(numbers[i])){
                *duplication=numbers[i];
                return true;
            }
            else{
                s.insert(numbers[i]);
            }
        }
        return false;
    }
};