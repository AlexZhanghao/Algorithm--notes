#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int count = 0;
		for (int i = 0; i < pushV.size(); ++i) {
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[count]) {
				s.pop();
				++count;
			}
		}
		return count == popV.size();
	}
};
