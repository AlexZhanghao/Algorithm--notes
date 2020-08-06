#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int n = s.size();
		if (n == 0) return 0;
		stack<char> cal;
		int i = 0;
		while (i < n) {
			if (s[i] == ' ') {
				++i;
				continue;
			}
			else if (s[i] == '*' || s[i] == '/') {
				string str1, str2;
				while (!cal.empty()&&cal.top() >= '0'&&cal.top() <= '9') {
					str1 = cal.top() + str1;
					cal.pop();
				}
				int j = i + 1;
				while ((s[j] >= '0'&&s[j] <= '9')||s[j]==' ') {
					if(s[j]!=' ')str2 += s[j];
					++j;
				}
				int a1 = atoi(str1.c_str());
				int a2 = atoi(str2.c_str());
				int a = 0;
				if (s[i] == '*') a = a1 * a2;
				else a = a1 / a2;
				string str3 = to_string(a);
				for (int k = 0; k < str3.size(); ++k) cal.push(str3[k]);
				i = j;
			}
			else {
				cal.push(s[i]);
				++i;
			}
		}

		string s2;
		while (!cal.empty()) {
			s2 += cal.top();
			cal.pop();
		}
		reverse(s2.begin(), s2.end());

		i = 0;
		int ret = 0;
		while (i < s2.size()) {
			string str;
			if (s2[i] == '+' || s2[i] == '-') {
				str += s2[i];
				++i;
			}

			while (i < s2.size() && (s2[i] != '+') && (s2[i] != '-')) {
				str += s2[i];
				++i;
			}

			ret += atoi(str.c_str());
		}

		return ret;
	}
};