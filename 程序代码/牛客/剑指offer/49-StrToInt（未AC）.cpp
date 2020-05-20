#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//这题遇到-2147483649时，始终解不出来。
class Solution {
public:
	int StrToInt(string str) {
		if (str.size() == 0) return 0;
		int out=0;
		string num;
		bool is_sym = false, is_negv = false;
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') continue;
			else if (str[i] == '+' || str[i] == '-') {
				if (is_sym)  return 0;
				else {
					num += str[i];
					is_sym = true;
				}
			}
			else if (str[i] > 47 && str[i] < 58) {
				num.push_back(str[i]);
			}
			else return 0;
		}

		if (num[0] == '+') num.erase(0, 1);
		else if (num[0] == '-') {
			is_negv = true;
			num.erase(0, 1);
		}

		for (int j = 0; j < num.size(); ++j) {
			out = out * 10 +(num[j] - '0');
		}
        if(is_negv) out=-out;
		return out;
	}
};

//一个牛客上的简化解法
class Solution2 {
public:
    int StrToInt(string str) {
        if (str.empty())
            return 0;
        int sum = 0;
        int i = 0;
        if (str[0] == '+' || str[0] == '-')
            i = 1;
 
        for (; i < str.size(); i++) {
            if (str[i] >= '0' && str[i] <= '9')
                sum = sum * 10 + (str[i]-'0');
            else
                return 0;
        }
 
        if (str[0] == '-')
            return -sum;
        else
            return sum;
    }
};