#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	vector<vector<int>> book;
	while (getline(cin, s)) {
		int i = 1;
		for (int j = 0; j < n; ++j) {
			vector<int> nums;
			
			while (s[i] != ']') {
				if (s[i] == '[' || s[i] == ']' || s[i] == ',' || s[i] == ' ') {
					++i;
				}
				else {
					string a;
					while (s[i] >= '0'&&s[i] <= '9') {
						a += s[i];
						++i;
					}
					int b = atoi(a.c_str());
					nums.push_back(b);
				}
			}
			++i;

			for (int j = 0; j < nums.size(); ++j) {
				cout << nums[j] << " ";
			}
			
			cout << endl;
		}
		++i;
	}
	getchar();
	return 0;
}