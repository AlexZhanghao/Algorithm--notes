#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void reversearray(vector<int> &nums, int k) {
	int n = nums.size();
	int start = 0;

	while (start < n)
	{
		reverse(nums.begin()+ start, nums.begin() + start + k);
		start += k;
	}

	return;
}

void merge(vector<int> &nums, vector<int>& helper, int l, int r, int &pairnum) {
	if (l >= r) return;
	int mid = l + ((r - l) >> 1);
	merge(nums, helper, l, mid, pairnum);
	merge(nums, helper, mid + 1, r, pairnum);

	int ptrl = l, ptrr = mid + 1, ptr = l;
	while (ptrl <= mid && ptrr <= r) {
		if (helper[ptrl] <= helper[ptrr]) {
			nums[ptr] = helper[ptrl];
			++ptr;
			++ptrl;
		}
		else {
			nums[ptr] = helper[ptrr];
			++ptr;
			++ptrr;
			pairnum += mid - ptrl + 1;
		}
	}

	while (ptrl <= mid) {
		nums[ptr] = helper[ptrl];
		++ptr;
		++ptrl;
	}
	while(ptrr <= r){
		nums[ptr] = helper[ptrr];
		++ptr;
		++ptrr;
	}

	for (int i = l; i <= r; ++i) {
		helper[i] = nums[i];
	}

	return;
}

int inversepairs(vector<int> &nums) {
	int n = nums.size();
	vector<int> tem = nums;
	vector<int> helper = nums;
	int ret=0;
	merge(tem, helper, 0, n - 1, ret);
	return ret;
}

int main() {
	int n = 0;
	cin >> n;
	int count = 1 << n;
	vector<int> nums(count, 0);
	for (int i = 0; i < count; ++i) {
		cin >> nums[i];
	}

	int m = 0;
	cin >> m;
	vector<int> qi(m, 0);
	for (int i = 0; i < m; ++i) {
		cin >> qi[i];
	}

	vector<int> ret(m, 0);
	for (int i = 0; i < m; ++i) {
		int two_pow_qi = 1 << qi[i];
		reversearray(nums, two_pow_qi);
		ret[i] = inversepairs(nums);
	}

	for (int i = 0; i < m; ++i) {
		cout << ret[i] << endl;
	}
	getchar();
	return 0;
}