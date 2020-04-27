#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
                int i=0,count=0;
                while(str[i]!='\0'){
                        if(str[i]==' ') ++count;
                        ++i;
                }
                --i;
                count+=count;
                int newlen=i+count;
                str[newlen+1]='\0';
                for(int j=i;j>=0;--j){
                        if(str[j]!=' ') str[newlen--]=str[j];
                        else{
                                str[newlen--]='0';
                                str[newlen--]='2';
                                str[newlen--]='%';
                        }
                }
                
	}
};