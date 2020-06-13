#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        if(n==0) return "";
        int l=n-1,r=n-1,len=0;
        string out;
        while(l>=0){
            while(l>=0&&s[l]==' ') --l;
            r=l;
            while(l-1>=0&&s[l-1]!=' ') --l;
            len=r-l+1;
            out+=s.substr(l,len);
            out+=' ';
            --l;
        }
        out.erase(out.end()-1);
        return out;
    }
};

//在原来的基础上进行翻转，这里用到的主要是这个reverse函数
class Solution2 {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin) {
            //找到了下一个字符串的起点
            if (s[begin] != ' ') {
                //放一个空格做间隔
                if (pos != 0) { 
                    s[pos++] = ' ';
                }
                int end = begin;
                //前移
                while (end < n && s[end] != ' ') {
                    s[pos++] = s[end++];
                }
                //局部反转
                reverse(s.begin() + pos - (end - begin), s.begin() + pos); 
                begin = end;
            }
        }
        //末尾可能有多余空格
        s.erase(s.begin() + pos, s.end());
        return s;
    }
};