#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int>& a,int left,int right){
	if (left >= right) return -1;
	int l = left, r = right-1;
	while (l < r) {
		while (l<r&&a[r]>a[left]) --r;
		while (l < r&&a[l] <= a[left]) ++l;
		swap(a[l], a[r]);
	}
	swap(a[left], a[l]);
	return l;
}

int findK(vector<int> &a,int left,int right,int k) {
    if(k>=right) return -1;
	int pos = partition(a, left, right);
	if (pos == k) return a[pos];
	else if (pos > k) return findK(a, left, pos, k);
	else return findK(a, pos + 1, right, k);
}

int main() {
	vector<int> a = { 1,4,5,3,7,9,2,6,8,10 };
	int m = findK(a, 0, a.size(), 9);
	cout << m << endl;
	getchar();
	return 0;
}