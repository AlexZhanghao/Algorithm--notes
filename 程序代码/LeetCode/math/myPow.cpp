#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {        
        if(n<0){
            if(n==-2147483648){
                return 1/(myPow(x,INT_MAX)*x);
            }
            return 1/myPow(x,-n);
        } 
        return QuickPow(x,n);
    }

    double QuickPow(double x,int n){
        double qp=0;
        if(x==0) return 0;
        if(n>=2){
            double q=0;
            if(n%2==0){
               q=QuickPow(x,n/2);
                return q*q;
            }
            else{
                q=QuickPow(x,n/2);
                return q*q*x;
            }
        }else if(n==1){
            return x;
        }
        return 1.0;
    }
};