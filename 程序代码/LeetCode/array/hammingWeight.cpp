#include<iostream>
#include<vector>

using namespace std;

//这里的思路是对于任意数字 n ，将 n 和 n−1 做与运算，会把最后一个 1 的位变成 0 ，也是很秀了。
//当然也有常规的用1开始一一做与比较，每比一次左移一位。
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int  count=0;
        while(n>0){
            n=n&(n-1);
            ++count;
        }
        return count;
    }
};