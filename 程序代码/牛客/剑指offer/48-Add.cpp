#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2){
        while(num2!=0){
            int c=(num1&num2)<<1;
            num1=num1^num2;
            num2=c;
        }
        return num1;
    }
};