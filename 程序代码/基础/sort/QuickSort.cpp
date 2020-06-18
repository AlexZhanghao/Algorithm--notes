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

//自我总结快排三要素如下：
//1、假设标记位是最左边的结点 
//2、要先从右边的开始比较 
//3、左边的要从标记位开始，不要用标记位+1
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