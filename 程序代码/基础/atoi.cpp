#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int n=str.size();
        if(n<1) return 0;
        int sym=1;
        int i=0,out=0;
        while(str[i]==' ') ++i;
        //把判断正负移到for外会更加简洁
        if(str[i]=='+'){
            ++i;
        }
        else if(str[i]=='-'){
            sym=-1;
            ++i;
        }
        for(;i<n;++i){
            if(str[i]>='0'&&str[i]<='9'){
                //这里首先要判断越界
                if(out>INT_MAX/10||out==INT_MAX/10&&str[i]-'0'>=INT_MAX%10) return INT_MAX;
                if(out<INT_MIN/10||out==INT_MIN/10&&str[i]-'0'>=-(INT_MIN%10)) return INT_MIN;
                out=out*10+sym*(str[i]-'0');              
            }
            else{
                break;
            }
        }

        return out;
    }
};