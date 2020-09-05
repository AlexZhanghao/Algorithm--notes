#include<iostream>
#include<vector>

using namespace std;

void dfs(const vector<int>& prearray, int pleft, int pright, const vector<int> &inarray, int ileft, int iright, vector<int> &postarray, int left, int right) {
	if (ileft > iright) return;

	int flag = prearray[pleft];
	postarray[right] = flag;
	if (ileft == iright) return;
	int mid = left;
	while (mid < iright&&inarray[mid] != flag) ++mid;
	int l = mid - ileft, r = iright - mid;
	dfs(prearray, pleft + 1, pleft + l, inarray, ileft, mid - 1, postarray, left, left + l - 1);
	dfs(prearray, pleft + l + 1, pright, inarray, mid + 1, iright, postarray, left + l, right - 1);
	return;
}

vector<int> PreandInToPost(vector<int> prearray, vector<int> inarray) {
	int n = prearray.size();
	vector<int> postarray(n, 0);
	dfs(prearray, 0, n - 1, inarray, 0, n - 1, postarray, 0, n - 1);
	return postarray;
}

int main() {
	vector<int> pre = { 1,2,4,7,5,9,3,6,8,10 };
	vector<int> in = { 7,4,2,5,9,1,6,3,8,10 };
	vector<int> post = PreandInToPost(pre, in);
	for (int i = 0; i < post.size(); ++i) cout << post[i] << " ";
	return 0;
}