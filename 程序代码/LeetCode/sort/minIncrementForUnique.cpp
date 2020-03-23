#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int asize=A.size();
        if(asize==0){
            return 0;
        }

        sort(A.begin(),A.end());

        int ans=0,cnt=0;
        for(int i=1;i<asize;++i){
            if(A[i]==A[i-1]){
                ans-=A[i];
                ++cnt;
            }
            else{
                int give = min(cnt, A[i] - A[i - 1] - 1);
                ans += give * (give + 1) / 2 + give * A[i-1];
                cnt -= give;
            }
        }

        if(cnt){
            ans += cnt * (cnt + 1) / 2 + cnt * A[asize - 1];
        }

        return ans;
    }
};