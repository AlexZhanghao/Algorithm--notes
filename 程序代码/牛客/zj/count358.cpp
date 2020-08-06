//区间[a, b], a 和 b 都是正整数， 问：区间内不包含数字 3 5 8 的整数个数。
#include<iostream>
#include<vector>

using namespace std;

//暴力拆解
int count358(int a, int b) {
	int tmp = 0;
	for (int i = a; i <= b; ++i) {
		int num = i;
		while (num) {
			int k = num % 10;
			num = num / 10;
			if (k == 3 || k == 5 || k == 8) {
				++tmp;
				break;
			}
		}
	}

	return b - a + 1 - tmp;
}

int main() {
	cout << count358(1, INT_MAX) << endl;
	getchar();
	return 0;
}
