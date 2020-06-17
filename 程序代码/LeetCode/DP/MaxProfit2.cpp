#include<vector>

using namespace std;

//贪心算法，把每天都作为交易日
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n<2) return 0;

    int maxprofit=0;
    for(int i=1;i<n;++i){
        if(prices[i]-prices[i-1]>0) maxprofit+=(prices[i]-prices[i-1]);
    }

    return maxprofit;
}

//峰谷法
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int max_profit=0;
    int peak=0;
    int valley=0;

    if(n==0){
        return 0;
    }
    if(n==1){
        return prices[0];
    }

    int i=0;
    while(i<n-1){
        while(i<n-1&&(prices[i]>=prices[i+1])){
            ++i;
        }

        valley=prices[i];
        while(i<n-1&&(prices[i]<=prices[i+1])){
            ++i;
        }
        peak=prices[i];
        if(peak-valley>max_profit){
            max_profit+=peak-valley;
        }
    }

    return max_profit;        
}