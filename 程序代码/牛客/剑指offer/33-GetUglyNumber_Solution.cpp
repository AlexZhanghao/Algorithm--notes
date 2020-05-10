#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//力扣上能够，但牛客上显示越界！！！
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //不懂为什么牛客必须加上下面这行才能行
        if (index < 7)return index;
        vector<int> dp(index,0);
        dp[0]=1;
        int ptr2=0,ptr3=0,ptr5=0;
        for(int i=1;i<index;++i){
            dp[i]=min(min(2*dp[ptr2],3*dp[ptr3]),5*dp[ptr5]);
            //这里2*3与3*2是重复的，所以直接一路if下去，遇到相等的都加1，而不用if-else
            if(dp[i]==2*dp[ptr2]) ++ptr2;
            if(dp[i]==3*dp[ptr3]) ++ptr3;
            if(dp[i]==5*dp[ptr5]) ++ptr5;
            
        }
        return dp[index-1];
    }
};