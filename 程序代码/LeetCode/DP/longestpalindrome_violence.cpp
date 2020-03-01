/******最长回文子串******
LONGEST-PALINDROME(s)
let m[1...n,1..n],w[1...n,1..n] be new tables
for i=1 to n
    m[i,i]=1
    w[i,i]=i
for l=2 to n
    for i=1 to n-l+1
        j=i+l-1
        m[i,j]=∞
        for r=i to j
        k=s[i...r]
        if PALINDROMEDETECTION(k)
           m[i,j]=r-i+1
           w[i,j]=w[i,j-1]
        else 
           m[i,j]=m[i,j-1]+1
           w[i,j]=w[i,j-1]
return m[w[1,n]...(w[1,n]+m[1,n]-1)]
******最长回文子串******/

#include<iostream>
#include<string>
#include<vector>

#define INT_MAX 0x7fffffff

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        int** m=new int*[n];
        int** w=new int*[n];
        for(int i=0;i<n;++i){
            m[i]=new int[n];
            w[i]=new int[n];
        }

        for(int i=0;i<n;++i){
            m[i][i]=1;
            w[i][i]=i;
        }

        for(int l=2;l<n+1;++l){
            for(int i=0;i<n-l+1;++i){
                int j=i+l-1;
                m[i][j]=INT_MAX;
                for(int r=i;r<j;++r){
                    string k;
                    for(int p=i;p<r+1;++p){
                        k+=s[p];
                    }
                    if(PalindromeDetection(k)){
                        m[i][j]=r-i+1;
                        w[i][j]=w[i][i];
                    }else{
                        m[i][j]=m[i][j-1];
                        w[i][j]=w[i][i];
                    }
                }
            }
        }

 	int strat_position = w[0][0];
	int length = m[0][0];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (m[i][j] > length) {
				length = m[i][j];
				strat_position = w[i][j];
			}
		}
	}

	string longest_palindrome;
	for (int i = 0; i < length; ++i) {
		longest_palindrome += s[strat_position + i];
	}
	return longest_palindrome;

    }
    
bool PalindromeDetection(string k) {
	string str = k;
	reverse(str.begin(), str.end());
	return str == k;
}


};
