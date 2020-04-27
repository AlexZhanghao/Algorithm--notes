#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		stack<int> q1;
		stack<int> q2;
		for (int i = 0; i < n ; ++i) {
			string s1, s2;
			cin >> s1;
			if (s1[0] == 'a') cin >> s2;;
			if (s1[0] == 'a') {
				int m = s2[0] - 48;
				if (q1.empty()) {
					q1.push(m);
					q2.push(m);
				}
				q1.push(m);
			}
			else {
				if (s1[1] == 'o') {
					int q2t = q2.top();
					q2.pop();
					while (q1.top() != q2t) {
						q2.push(q1.top());
						q1.pop();
					}
					q1.pop();
					q2t = q2.top();
					while (!q2.empty()) {
						q1.push(q2.top());
						q2.pop();
					}
					q2.push(q2t);
				}
				else {
					cout << q2.top() << endl;
				}
			}
		}
	}
	return 0;
}