#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
	vector<int> nums;
	unordered_map<int, int> um;
	for (int i = 0; i < 10; ++i) {
		nums.push_back(i);
		++um[i];
	}

	cout << nums.size() << endl;
	cout << um.size() << endl;

	for (auto j = nums.begin(); j != nums.end();) {
		j = nums.erase(j);
	}

	for (auto k = um.begin(); k != um.end();) {
		um.erase(k++);
	}

	cout << nums.size() << endl;
	cout << um.size() << endl;

	return 0;
}