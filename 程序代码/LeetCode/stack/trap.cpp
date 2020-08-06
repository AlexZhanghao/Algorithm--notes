#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3) return 0;
        vector<int> max_left(n,0),max_right(n,0);
        for(int i=1;i<n;++i){
            max_left[i]=max(max_left[i-1],height[i-1]);
        }
        for(int j=n-2;j>=0;--j){
            max_right[j]=max(max_right[j+1],height[j+1]);
        }

        stack<int> s;
        s.push(0);
        int rain=0;
        for(int i=1;i<n;++i){
            if(height[i]>height[s.top()]){
                while(!s.empty()&&height[i]>height[s.top()]){
                    int cur=s.top();
                    s.pop();
                    if(!s.empty())rain+=min(max_left[cur],max_right[cur])-height[cur];
                }
            }
            s.push(i);
        }

        return rain;
    }
};