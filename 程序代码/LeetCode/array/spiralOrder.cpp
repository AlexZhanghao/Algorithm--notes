#include<iostream>
#include<vector>

using namespace std;

//看了一个老哥的题解，是对官解的一个简洁的代码实现，关键在于这四个检查
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();
        if(row==0) return {};
		int cloumn = matrix[0].size();
		int left = 0;
		int right = cloumn;
		int up = 0;
		int down = row;
		vector<int> cnt;
		while (true) {
			//向右
			for (int i=left; i < right; ++i) {
				cnt.push_back(matrix[up][i]);
			}
			if (++up >= down) break;//下沉一行并检查
			//向下
			for (int i=up; i < down; ++i) {
				cnt.push_back(matrix[i][right - 1]);
			}
			if (--right <= left) break;//左移一行并检查
			//向左
			for (int i = right - 1; i >= left; --i) {
				cnt.push_back(matrix[down - 1][i]);
			}
			if (--down <= up) break;//上升一行并检查
			//向上
			for (int i = down - 1; i >= up; --i) {
				cnt.push_back(matrix[i][left]);
			}
			if (++left >= right) break;//右移一行并检查
		}
		return cnt;
	}

};
