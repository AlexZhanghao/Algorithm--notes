//小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
//小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，
//请问他第一天最多能吃多少块巧克力。
//例：input：出差 4 天，７块奶糖
//　　output：4

#include<iostream>
#include<vector>

using namespace std;

bool enougheat(int n, int cur, int m) {
	while (m--) {
		n -= cur;
		if (n < 0) return false;
		cur = (cur + 1) >> 1;
	}

	return true;
}

int mostcandys(int time, int num) {
	int left = 1, right = num;
	while (left < right) {
		int mid = left + ((right - left) >> 1);
		bool is_enough = enougheat(num, mid, time - 1);

		if (is_enough) left = mid;
		else right = mid - 1;
	}

	return left;
}

int main() {
	cout << mostcandys(4, 7) << endl;
	return 0;
}