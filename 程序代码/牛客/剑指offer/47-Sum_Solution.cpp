#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        bool num=n>1&&Sum_Solution(n-1);        
        sum+=n;
        return sum;
    }

private:
    int sum=0;
};