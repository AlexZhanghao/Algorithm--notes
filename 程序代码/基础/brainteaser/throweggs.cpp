//n层楼，m个鸡蛋问题
//m个软硬程度一样但未知的鸡蛋，它们有可能都在一楼就摔碎，也可能从一百层楼摔下来没事。
//有座n层的建筑，要你用这m鸡蛋确定哪一层是鸡蛋可以安全落下的最高位置。
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int superEggDrop(int K, int N) {
    //dp[i][j]：一共有 j 层楼梯的情况下，使用 i 个鸡蛋的最少实验的次数
    vector<vector<int>> dp(K+1,vector<int>(N+1,0));

    //只有一层楼时，鸡蛋数大于0时都只需尝试一次
    for(int i=1;i<=K;++i) dp[i][1]=1;
    //只有一个鸡蛋时，楼层数大于0时在最差情况下需要尝试与楼层数相等的次数
    for(int j=1;j<=N;++j) dp[1][j]=j;

    for(int i=2;i<=K;++i){
        for(int j=2;j<=N;++j){
            int left=1,right=j;
            while(left<right){
                int mid=left+((right-left+1)>>1);
                if(dp[i-1][mid-1]>dp[i][j-mid]) right=mid-1;
                else left=mid;
            }
            dp[i][j]=max(dp[i-1][left-1],dp[i][j-left])+1;
        }
    }

    return dp[K][N];
}