#include<iostream>
#include<vector>
#include<string>

using namespace std;

int qtop(vector<int> &a) {
	if (a.size() == 0) return -1;
	return a[0];
}

int qpop(vector<int> &a) {
	if (a.size() == 0) return -1;
	// vector<int> b;
	// for (int i = 1; i < a.size(); ++i) b.push_back(a[i]);
	// a = b;
    a.erase(a.begin());
	return 1;
}

int main() {
	int T;
	while (cin >> T) {
		for (int i = 0; i < T; ++i) {
			vector<int> v;
			int Q;
			cin >> Q;
			for (int j = 0; j < Q; ++j) {
				string s, k;
				cin >> s;
				if (s[0] == 'P'&&s[1]=='U') cin >> k;
				if (s[0] == 'P') {
					if (s[1] == 'U') {
						int m = k[0] - 48;
						v.push_back(m);
					}
					else {
						int q = qpop(v);
						if (q == -1) cout << -1 << endl;
					}
				}
				else if (s[0] == 'T') {
					cout << qtop(v) << endl;
				}
				else if (s[0] == 'S') {
					cout << v.size() << endl;
				}
				else {
					v = {};
				}
			}
		}
	}
	return 0;
}