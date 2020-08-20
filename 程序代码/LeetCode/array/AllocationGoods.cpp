//现在有n个物品，每个物品都有一个价值，现在想将这些物品分给两个人，要求这两个人分到的物品价值总和相同(个数可以不同，总价值相同即可)，
//剩下的物品就要扔掉，现在想知道最少需要扔多少价值的物品才能满足要求分给两个人。
//如：30 60 5 15 30
//输出：20（5+15）

#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<unordered_set>
using namespace std;

int ans = INT_MAX;
int sum = 0;

void dfs(const vector<int> &nums,int pos, int x, int y,const int&n) {
	if (pos >= n) {
		if (x == y)
			ans = min(ans, sum - x - y);
		return;
	}
	dfs(nums,pos + 1, x + nums[pos], y,n);
	dfs(nums,pos + 1, x, y + nums[pos],n);
	dfs(nums,pos + 1, x, y,n);
}

int main() {
	vector<int> nums = { 30,60,5,15,30 };
	sum = accumulate(nums.begin(), nums.end(),0);
	dfs(nums,0, 0, 0, nums.size());
	cout << ans << endl;
	getchar();
	return 0;
}