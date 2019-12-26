#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();

    if(n==0){
        return 0;
    }
    if(n==1){
        return prices[0];
    }

    int max_profit=0;
    bool is_buy=0;

    for(int i=0;i<n-1;++i){
        if(prices[i]<prices[i+1]){
            max_profit-=prices[i];
            int j=i+1;
            while(j<n){
                if(prices[j]>prices[i]&&prices[j]>prices[j+1]){
                    max_profit+=prices[j];
                    i=j;
                    break;
                }else{
                    ++j;
                }
            }
        }
    }

    return max_profit;
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
        while(i<n-1&&(prices[i]>prices[i+1]||prices[i]==prices[i+1])){
            ++i;
        }
        valley=prices[i];
        while(i<n-1&&(prices[i]<prices[i+1]||prices[i]==prices[i+1])){
            ++i;
        }
        peak=prices[i];
        max_profit+=peak-valley;
    }

    return max_profit;        
}