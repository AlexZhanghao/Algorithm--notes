#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int s_size = s.size();
		if (s_size == 0) {
			return 0;
		}

		unordered_map<char, int> c;
		int i = 0, j = 0, ls = 0;
		while (j < s_size) {
			if (c.find(s[j]) != c.end()&&c[s[j]]>=i) {
				i = c[s[j]];
				++i;				
			}
			else {
				c[s[j]] = j;
				++j;
				ls = max(j - i, ls);
			}
		}

		return ls;
	}
};

int main() {
	string a = "abcdefg";
	Solution s;
	s.lengthOfLongestSubstring(a);
	system("pause");
}