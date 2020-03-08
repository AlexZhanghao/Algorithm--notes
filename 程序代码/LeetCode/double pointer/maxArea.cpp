#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int hsize=height.size();
        if(hsize<2){
            return 0;
        }

        int s_ptr=0;
        int e_ptr=hsize-1;
        int max_area=0;
        int h=0;
        int w=0;
        while(s_ptr!=e_ptr){
            w=e_ptr-s_ptr;
            if(height[s_ptr]>height[e_ptr]){
                h=height[e_ptr];
                --e_ptr;
            }else{
                h=height[s_ptr];
                ++s_ptr;
            }

            int area=h*w;
            if(area>max_area){
                max_area=area;
            }
        }

        return max_area;
    }
};