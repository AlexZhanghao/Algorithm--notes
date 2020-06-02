#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

//总体而言用while相比for能省掉不少麻烦。
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

class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();
		if (n == 0) return 0;
		unordered_map<char, int> book;
		int count = 1, start = 0;
		for (int i = 0; i < n; ++i) {
			if (book.count(s[i])) {
				//如遇到"abba"这种情况，在第二次遇到a时，start会回退到起始位置，但这是错误的，所以需要先判断一下。
				if(book[s[i]] + 1>=start) start = book[s[i]] + 1;
				book[s[i]] = i;
			}
			else {
				book[s[i]] = i;
			}
			//如遇到“abc”这种没有重复的情况，加入这里是"i-start"就会得到2，所以要在这里加1，也因此要让start = book[s[i]] + 1;
			count = max(i - start + 1, count);
		}

		return count;
	}
};

int main() {
	string a = "abcdefg";
	Solution s;
	s.lengthOfLongestSubstring(a);
	system("pause");
}