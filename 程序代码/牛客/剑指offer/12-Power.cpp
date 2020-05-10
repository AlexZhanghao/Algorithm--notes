#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0) return 1;
        bool is_nega=false;
        if(exponent<0){
            is_nega=true;
            exponent=-exponent;
        }
        double mid=base;
        --exponent;
        while(exponent>0){
            if(exponent%2==1){
                base=(base*mid);
                --exponent;
            }
            else{
                mid=(mid*mid);
                exponent=exponent/2;
            }
        }
        if(is_nega) base=1/base;
        return base;
    }
};