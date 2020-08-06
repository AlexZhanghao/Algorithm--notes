//传入一个int型数组，返回该数组能否分成两组，使得两组中各元素加起来的和相等，
//并且，所有5的倍数必须在其中一个组中，所有3的倍数在另一个组中（不包括5的倍数），
//能满足以上条件，返回true；不满足时返回false

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

bool dfs(vector<int> &a, int target, int cur, int pos, int n) {
	if (pos > n) return false;

	for (int i = pos; i <= n; ++i) {
		cur += a[i];
		if (cur == target) return true;
		else if (cur > target) return false;

		if (dfs(a, target, cur, i + 1, n)) return true;

		cur -= a[i];
	}

	return false;
 }

bool group(vector<int> &nums) {
	int n = nums.size();
	vector<int> num3, num5, other;
	for (int i = 0; i < n; ++i) {
		if (nums[i] % 3 == 0) num3.push_back(nums[i]);
		else if (nums[i] % 5 == 0) num5.push_back(nums[i]);
		else other.push_back(nums[i]);
	}

	int num3all = accumulate(num3.begin(), num3.end(), 0);
	int num5all = accumulate(num5.begin(), num5.end(), 0);
	int diff = abs(num3all - num5all);
	if (diff) other.push_back(diff);
	int sum = accumulate(other.begin(), other.end(), 0) ;

	if (sum % 2) return false;

	return dfs(other, sum/2, 0, 0, other.size() - 1);
}

int main() {
	vector<int> nums = { 3,3,3,6,10,5,1,2,4 };
	cout << group(nums) << endl;
	return 0;
}