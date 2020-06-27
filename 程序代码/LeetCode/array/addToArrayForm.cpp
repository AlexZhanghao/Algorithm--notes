#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n=A.size();
        vector<int> b;
        while(K>0){
            b.push_back(K%10);
            K/=10;
        }

        if(n>b.size()){
            int diff=n-b.size();
            for(int i=0;i<diff;++i) b.push_back(0);
        }
        else if(n<b.size()){
            int diff=b.size()-n;
            vector<int> a(diff,0);
            a.insert(a.end(),A.begin(),A.end());
            A=a;
            n=b.size();
        }

        reverse(b.begin(),b.end());
        bool is_on=false;
        for(int i=n-1;i>=0;--i){
            int k=A[i]+b[i];
            if(is_on){
                ++k;
                is_on=false;
            }

            if(k>=10){
                is_on=true;
                k%=10;
            }
            A[i]=k;
        }

        if(is_on){
            vector<int> a={1};
            a.insert(a.end(),A.begin(),A.end());
            A=a;
        }
        return A;
    }
};