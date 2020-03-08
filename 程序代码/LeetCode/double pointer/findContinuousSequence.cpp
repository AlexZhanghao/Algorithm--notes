#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target==0){
            return {};
        }

        int ptr_small;
        int ptr_large;
        int sum=0;
        int limit=(target/2)+1;
        vector<vector<int>> conseq;

        for(ptr_small=1;ptr_small<limit;++ptr_small){
            ptr_large=ptr_small+1;
            sum=ptr_small+ptr_large;
            while(sum<target){
                sum+=++ptr_large;
            }

            if(sum==target){
                vector<int> a;
                for(int i=ptr_small;i<ptr_large+1;++i){
                    a.push_back(i);
                }
                conseq.push_back(a);
            }
        }

        return conseq;
    }
};

//官方的双指针法，它这里一个是用了高斯法，还有一个就是利用了之前的结果。
class Solution2 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>vec;
        vector<int> res;

        //注意这里，当l增长到刚好等于或大于target时，它选择的是++l，
        //这样就把这一列数里面最小的一个消去了，
        //通过不断的消去最小值直到这列数的和等于或者小于target,
        //这里妙就妙在不用每次++l后r再从l+1重来，
        //其实中间很大一部分已经是确认小于target的了，根本就不必再去重新计算
        //它的终止条件l>=r也值得品味一番。
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target){
                res.clear();
                for (int i = l; i <= r; ++i) res.emplace_back(i);
                vec.emplace_back(res);
                l++;
            }
            else if (sum < target) r++;
            else l++;
        }

        return vec;
    }
};