#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

string uncompress(string s) {
	int n = s.size();
	string ret;
	stack<char> _sk;
	int pos = 0;
	while (pos < n) {
		if (s[pos] != ']') _sk.push(s[pos]);
		else {
			string a;
			while (_sk.top() != '[') {
				a += _sk.top();
				_sk.pop();
			}
			_sk.pop();
			reverse(a.begin(), a.end());
			int num = 0;
			int pos_a = 0;
			while (pos_a < a.size()) {
				if (a[pos_a] == '|') {
					++pos_a;
					break;
				}

				num *= 10;
				num += a[pos_a] - '0';
				++pos_a;
			}
			a = a.substr(pos_a, a.size() - pos_a);
			string b;
			while (num--) {
				b += a;
			}

			for (int i = 0; i < b.size(); ++i) {
				_sk.push(b[i]);
			}
		}
		++pos;
	}

	while (!_sk.empty()) {
		ret += _sk.top();
		_sk.pop();
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	string s;
	while (cin >> s) {
		string ret = uncompress(s);
		cout << ret << endl;
	}

	return 0;
}