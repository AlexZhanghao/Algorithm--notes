#include<iostream>
#include<vector>

using namespace std;

void DownFilter(int *arr, int i, int k) {
	int cur = i, is_stop = false;
	while (!is_stop) {
		int tar = cur;
		if (cur * 2 < k&&arr[cur] > arr[cur * 2]) {
			tar = cur * 2;
		}
		if ((cur * 2 + 1) < k&&arr[tar] > arr[cur * 2 + 1]) {
			tar = cur * 2 + 1;
		}
		if (tar != cur) {
			swap(arr[cur], arr[tar]);
			cur = tar;
		}
		else {
			is_stop = true;
		}
	}
}

void UpFilter(int *arr, int n) {
	if (n == 0) return;
	if (arr[n] < arr[n / 2]) {
		swap(arr[n], arr[n / 2]);
		n = n / 2;
	}
}

void MakeHeap(int *arr, int k) {
	for (int i = k/2; i >= 0; --i) {
		DownFilter(arr, i, k);
	}
	return;
}

void HeapSort(int *arr, int *sor, int k) {
	int i = 0;
	while (k >= 0) {
		sor[i] = arr[0];
		swap(arr[0], arr[k - 1]);
		++i; --k;
		DownFilter(arr, 0, k);
	}
}

int main() {
	int arr[10] = { 3,2,5,6,7,9,8,1,4,10 };
	int sor[10];
	MakeHeap(arr, 10);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	HeapSort(arr, sor, 10);
	for (int i = 0; i < 10; ++i) {
		cout << sor[i] << " ";
	}
	getchar();
	return 0;
}