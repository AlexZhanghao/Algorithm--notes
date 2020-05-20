#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//这题要注意的一点，在牛客上面用下标计算一直出错，目前看来是必须像下面这样解地址求解了
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==NULL)
            return false;
        if(*string=='+'||*string=='-')
            string++;
        if(*string=='\0')
            return false;
        int dot=0,num=0,nume=0;//分别用来标记小数点、整数部分和e指数是否存在
        while(*string!='\0'){
            if(*string>='0'&&*string<='9')
            {  
                string++;
                num=1;
            }
            else if(*string=='.'){
                if(dot>0||nume>0)
                    return false;
                string++;
                dot=1;
            }
            else if(*string=='e'||*string=='E'){
                if(num==0||nume>0)
                    return false;
                string++;
                nume++;
                if(*string=='+'||*string=='-')
                    string++;

                //这个之前倒是没想到e后面没接数字的情况下就结束是错误的
                if(*string=='\0')
                    return false;
            }
            else return false;
        }
        return true;
    }
 
};