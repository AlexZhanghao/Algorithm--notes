#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> merged;
		vector<int> median = { 0,0 };
		int vsize = intervals.size();
		int index = 0;

		if (vsize < 2) {
			return intervals;
		}

		QuickSort(intervals, 0, vsize - 1);

		merged.push_back(intervals[0]);

		for (int i = 1; i < vsize; ++i) {
			if (merged[index][1] < intervals[i][0]) {              
				merged.push_back(intervals[i]);
				++index;
			}
			else {
                if(merged[index][1]>intervals[i][1]){
                }else{
				    merged[index][1] = intervals[i][1];
                }
			}
		}
		return merged;
	}

	void QuickSort(vector<vector<int>> &A, int p, int r) {
		if (p < r) {
			int q = Partition(A, p, r);
			QuickSort(A, p, q - 1);
			QuickSort(A, q + 1, r);
		}
	}

	int Partition(vector<vector<int>> &A, int p, int r) {
		int x = A[r][0];
		int i = p - 1;
		for (int j = p; j < r; ++j) {
			if (A[j][0] <= x) {
				i++;
				Exchange(A[i], A[j]);
			}
		}
		Exchange(A[i + 1], A[r]);
		return i + 1;
	}

	void Exchange(vector<int> &a, vector<int> &b) {
		vector<int> c = a;
		a = b;
		b = c;
	}
};

int main() {
	vector<vector<int>> internal;
	vector<int> a = { 1,2 };
	vector<int> b = { 0,2 };
	internal.push_back(a);
	internal.push_back(b);

	Solution c;
	c.merge(internal);
}