#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int end=rotateArray.size()-1;
        int start=0;
        while(start<end){
            int mid=(start+end)/2;
            if(rotateArray[mid]>rotateArray[end]) start=mid+1;
            else if(rotateArray[mid]<=rotateArray[end]) end=mid;
        }
        return rotateArray[start];
    }
};