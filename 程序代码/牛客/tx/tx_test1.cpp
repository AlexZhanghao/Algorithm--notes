#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

//60%
int main() {
	string a;
	while (cin >> a) {
		stack<char> s;
		string b;
		string mid;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] == '[') {
				s.push(a[i]);
				while (!s.empty()) {
					++i;
					if (a[i] != ']') s.push(a[i]);
					else {
						//++i;//这里将']'给跳过,但由于在while的第一步就要++i，所以这里再加会导致连跳两格；
						string c;
						while (s.top() != '[') {
							char p = s.top();
							s.pop();
							c = p + c;
						}
						s.pop();//这里将'['给直接舍弃
						int ns = 0; string nstr;
                        //这里数字可能会大于9，所以不能用char转int的方式来做
						while (c[ns] != '|') {
							nstr += c[ns];
							++ns;
						}
						int cnum = atoi(nstr.c_str());
						string mmid;
						for (int k = ns + 1; k < c.size(); ++k) mmid += c[k];
						while (cnum != 0) {
							mid += mmid;
							--cnum;
						}
						//由于可能会有一个以上的'['在栈中，所以处理完一个'[]'后要检查下stack是否是空的
						if (s.empty()) break;
						else {
							for (int j = 0; j < mid.size(); ++j) s.push(mid[j]);
						}
                        //注意将mid清空
						mid = "";
					}
				}
				b += mid;
			}
			else {
				b += a[i];
			}
		}
		cout << b << endl;
	}
}