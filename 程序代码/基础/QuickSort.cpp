#include<iostream>
#include<vector>

using namespace std;

int Partition(int *arr, int l, int r);

void QuickSort(int *arr, int l, int r) {
	if (l >= r) return;
	int mid = (arr[(l + r) / 2]);
	if (arr[l] > mid&&arr[l] > arr[r - 1]) {
		mid > arr[r - 1] ? swap(arr[(l + r) / 2], arr[l]) : swap(arr[r - 1], arr[l]);
	}
	else if (arr[l] < mid&&arr[l] < arr[r - 1]) {
		mid < arr[r - 1] ? swap(arr[(l + r) / 2], arr[l]) : swap(arr[r - 1], arr[l]);
	}
	int i = Partition(arr, l, r);
	QuickSort(arr, l, i - 1);
	QuickSort(arr, i + 1, r);
}

int Partition(int *arr, int l, int r) {
	if (l >= r) return l;
	int left = l, right = r;
	while (left < right) {
		while (left < right&&arr[right] < arr[l]) --right;
		while (left < right&&arr[left] >= arr[l]) ++left;
		swap(arr[left], arr[right]);
	}
	swap(arr[l], arr[left]);
	return left;
}

int main() {
	int arr[10] = { 3,2,5,6,7,9,8,1,4,10 };
	QuickSort(arr,0,9);
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
    getchar();
    return 0;
}