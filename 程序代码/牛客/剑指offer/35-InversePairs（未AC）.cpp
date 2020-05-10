#include<iostream>
#include<vector>

using namespace std;

//只通过75%
class Solution {
public:
    int InversePairs(vector<int> data) {
        int dsize=data.size();
        vector<int> transcript(dsize);
        return (mergeSort(data,transcript,0,dsize-1))%1000000007;
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = (mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r))%1000000007;
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += ((j - (mid + 1)))%1000000007;
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += ((j - (mid + 1)))%1000000007;
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count%1000000007;
    }
};
