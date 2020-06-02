#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> out = { -1,-1 };
		int n = nums.size();
		if (n < 1) return out;
		int left = 0, right = n - 1, mid = 0;
		while (left < right) {
			mid = left + (right - left + 1) / 2;
			if (nums[mid] > target) right = mid - 1;
			else left = mid;

		}
		if (nums[left] != target) return out;
        out[0]=left;out[1]=left;
		int l = left, r = left;
        //下面这段可以注释掉，因为这里left肯定是nums中最后一个和target相等的值
		//while (r < n-1&&nums[r + 1] == target) ++r;
		while (l > 0 && nums[l - 1] == target) --l;
		if (l != r) {
			out[0] = l;
			out[1] = r;
		}
		return out;
	}
};

class Solution2 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> out = { -1,-1 };
		int n = nums.size();
		if (n < 1) return out;
		int left = 0, right = n - 1, mid = 0;
		while (left < right) {
			mid = left + (right - left ) / 2;
			if (nums[mid] < target) left = mid+1;
			else right=mid;

		}
		if (nums[left] != target) return out;
        out[0]=left;out[1]=left;
		int l = left, r = left;
		while (r < n-1&&nums[r + 1] == target) ++r;
        //下面这段可以注释掉，因为这里left肯定是nums中第一个和target相等的值
		//while (l > 0 && nums[l - 1] == target) --l;
		if (l != r) {
			out[0] = l;
			out[1] = r;
		}
		return out;
	}
};