#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.size(),n2=b.size();
        if(n1==0) return b;
        if(n2==0) return a;
        int n=0;
        if(n1>n2){
            int diff=n1-n2;
            string s1;
            for(int i=0;i<diff;++i) s1+='0';
            b=s1+b;
            n=n1;
        }
        else if(n1<n2){
            int diff=n2-n1;
            string s2;
            for(int i=0;i<diff;++i) s2+='0';
            a=s2+a;
            n=n2;
        }
        else n=n1;
        
        bool is_on=false;
        string out;
        int i=n-1;
        while(i>=0){
            if(!is_on){
                if(a[i]=='0'&&b[i]=='0') out+='0';
                else if(a[i]=='1'&&b[i]=='1'){
                    out+='0';
                    is_on=true;
                }
                else{
                    out+='1';
                }
            }
            else{
                if( a[i]=='0'&&b[i]=='0'){
                    out+='1';
                    is_on=false;
                }
                else if( a[i]=='1'&&b[i]=='1'){
                    out+='1';
                }
                else{
                    out+='0';
                }        
            }
            --i;
        }
        if(is_on) out+='1';
        reverse(out.begin(),out.end());
        return out;
    }
};