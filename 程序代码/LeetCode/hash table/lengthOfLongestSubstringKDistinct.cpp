#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n=s.size();
        unordered_map<char,int> um;
        int left=0,right=0,maxlen=0;
        int count=0;
        while(right<n){
            if(um[s[right]]==0){
                ++count;                
            }
            ++um[s[right]];

            while(count>k){
                if((--um[s[left++]])==0) --count;
            }

            maxlen=max(maxlen,right-left+1);
            ++right;
        }

        return maxlen;
    }
};

int main(){
    Solution s;
    string a="eceba";
    cout<<s.lengthOfLongestSubstringKDistinct(a,2)<<endl;
    return 0;
}