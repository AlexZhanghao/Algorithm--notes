#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		if (n < 2) return 0;
		int closenum = 0, diff = INT_MAX;
		int start = 0, left, right;
		sort(nums.begin(), nums.end());

		while (start < n - 2) {
			if (start > 0 && nums[start] == nums[start - 1]) {
				++start;
				continue;
			}
			left = start + 1;
			right = n - 1;
			while (left < right) {
				if (left > start + 1 && nums[left] == nums[left - 1]) {
					++left;
					continue;
				}

				int i = nums[start] + nums[left] + nums[right];
				int j =i - target;
				if (j == 0) return i;
				else if (j < 0) ++left;
				else --right;

				j=abs(j);
                if (j < diff) {
					diff = j;
					closenum = i;
				}
			}
			++start;
		}

		return closenum;
	}
};