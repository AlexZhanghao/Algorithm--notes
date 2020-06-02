#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
		int n1 = num1.size(), n2 = num2.size();
		vector<int> out(n1 + n2, 0);
		for (int i = 0; i < n1; ++i) {
			for (int j = 0; j < n2; ++j) {
				int tem = (num1[i] - '0')*(num2[j] - '0');
				out[i + j + 1] += tem % 10;
				out[i + j] += tem / 10;
			}
		}
        for(int m=n1+n2-1;m>=0;--m){
            if(out[m]>=10){
                out[m-1]+=out[m]/10;
                out[m]=out[m]%10;
            }
        }
		string mul;
		int start = 0;
        //这里要加上start<out.size()的条件，否则输入是两个0时会发生越界，当然也可以如开始所示，先检查是否有0存在，从而规避掉这个问题
		while (start<out.size()&&out[start] == 0) ++start;
		for (int k = start; k < out.size(); ++k) {
			mul += out[k] + '0';
		}
		return mul;
	}
};