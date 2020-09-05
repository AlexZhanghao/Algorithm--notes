#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> towerSee(vector<int>& nums) {
	int n = nums.size();
	stack<int> left, right;
	vector<int> l(n, 0), r(n, 0);

    //在使用单调栈进行记录的时候，要注意以取值，出栈，入栈的顺序进行
	for (int i = 0; i < n; ++i) {
		l[i] = left.size();		

		while (!left.empty()&&nums[i] >= nums[left.top()]) {
			left.pop();
		}

		left.push(i);
	}

	for (int i = n - 1; i >= 0; --i) {
		r[i] = right.size();

		while (!right.empty()&&nums[i] >= nums[right.top()]) {
			right.pop();
		}

		right.push(i);
	}

	vector<int> ret;
	for (int i = 0; i < n; ++i) {
		ret.push_back(r[i] + l[i] + 1);
	}

	return ret;
}

int main() {
	int n = 0;
	while (cin >> n) {
		vector<int> nums(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}

		vector<int> cansee = towerSee(nums);
		for (int i = 0; i < cansee.size(); ++i) {
			cout << cansee[i] << " ";
		}
		cout << endl;
	}

	return 0;
}