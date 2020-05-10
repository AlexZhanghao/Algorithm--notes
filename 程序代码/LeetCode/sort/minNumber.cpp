#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		int books = nums.size();
		if (books == 0) return "";
		vector<string> snums;
		for (int i = 0; i < nums.size(); ++i) snums.push_back(to_string(nums[i]));
		string min_num;
		QuickSort(snums, 0, books - 1);
		for (int i = 0; i < snums.size(); ++i) min_num += snums[i];
		return min_num;
	}

	void QuickSort(vector<string> &v, int left, int right) {
		if (left >= right) return;
		int vsize = v.size();
		int start = left, end = right;
		string norm = v[left];
		while (start < end) {
			while (start < end&&isleftmax(v[end], norm)) --end;
			while (start < end && !isleftmax(v[start], norm)) ++start;
			swap(v[start], v[end]);
		}
		if (isleftmax(norm, v[start])) swap(v[left], v[end]);
		QuickSort(v, left, start - 1);
		QuickSort(v, start + 1, right);
	}

	bool isleftmax(string a, string b) {
		string ab = a + b;
		string ba = b + a;
		if (ab > ba) return true;
		else return false;
	}
};