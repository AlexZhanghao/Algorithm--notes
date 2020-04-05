#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n > 1000) n = 1000;
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			q.push(i);
		}
		int c = 0;
		while (q.size() >1) {
			if (c == 2) {
				q.pop();
				c = 0;
				continue;
			}
			q.push(q.front());
			q.pop();
			++c;
		}
		int a = q.front();
		cout << a << endl;
	}
	return 0;
}
