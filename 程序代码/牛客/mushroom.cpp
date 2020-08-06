#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool mushroom(vector<int> &nums,int k){
    int n=nums.size();
    int life=k;
    for(int i=0;i<n;++i){
        if(nums[i]>0) life+=nums[i];
        --life;
        if(life==0) return false;
    }
    return true;
}

int main(){
    vector<int> mushrooms={1,-2,1,-1,2,1,-2,-2,1};
                        //3  2  2  1 2 2  1  0
    cout<<mushroom(mushrooms,3)<<endl;
    return 0;
}