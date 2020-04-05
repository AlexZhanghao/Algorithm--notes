#include<iostream>
#include<vector>

using namespace std;

//递归
class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n==1) return 0;
        return (lastRemaining(n-1,m)+m%n)%n;     
    }
};

//迭代
class Solution2 {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i != n + 1; ++i)
            f = (m + f) % i;
        return f;
    }
};
