#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

//这里关键是要选好遍历的起始位置，要选择左下角或者右上角作为初始位置才行
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0) return false;
		int cloumn = matrix[0].size();
		int start = row - 1;
		int i = 0;
		while (start >= 0 && i < cloumn) {
			if (matrix[start][i] == target) break;
			else if (matrix[start][i] > target) --start;
			else ++i;
		}
		return (i < cloumn&&start >= 0);
	}
};

