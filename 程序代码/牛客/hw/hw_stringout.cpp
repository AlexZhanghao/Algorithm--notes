#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main() {
	string s;	
	while (cin >> s) {
        int c = 0;
		unordered_map<char, int> hs;
		for (int i = 0; i < s.size(); ++i) {
			if (hs.count(s[i])) continue;
			int con = c;
			hs[s[i]] = con;
			++c;
		}

		auto ite1 = hs.begin();
		auto ite2 = hs.end();
		char p[100];
		for (; ite1 != ite2; ++ite1) {
			p[ite1->second] = ite1->first;
		}
		for (int j = 0; j < c; ++j) {
			cout << p[j];
		}
		cout << endl;
	}
	return 0;
}