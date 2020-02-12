#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();

    if(n==0||n==1){
        return 0;
    }

    int max_profit=0;
    int min_price=prices[0];

    for(int i=1;i<n;++i){
        if(prices[i]<min_price){
            min_price=prices[i];
        }
        if(prices[i]-min_price>max_profit){
            max_profit=prices[i]-min_price;
        }
    }

    return max_profit;        
}

//这里的方法有点味道，感觉这属于一类问题
//不过确实没用到动态规划，因为问题其实并不符合最优子结构