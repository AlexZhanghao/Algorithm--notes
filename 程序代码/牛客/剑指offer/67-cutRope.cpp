#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int cutRope(int number) {
        if(number==0||number==1||number==2) return number;
        int a=number/3;
        int b=number%3;
        int out=0;
        switch (b)
        {
        case 0:
            out=QuickPow(a);
            break;

        case 1:
            out=QuickPow(a-1)*4;
            break;

        case 2:
            out=QuickPow(a)*2;
            break;
            
        default:
            break;
        }
        return out;
    }

    int QuickPow(int n){
        int i=3;
        int out=1;
        while(n>0){
            if(n%2==1){
                out*=i;
                --n;
            }
            else{
                i*=i;
                n=n/2;
            }
        }
        return out;
    }

};