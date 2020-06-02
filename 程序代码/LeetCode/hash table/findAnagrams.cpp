#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

//hash_map扫描，结果超时
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size();
        int n=p.size();
        if(m==0||n==0) return{};
        sort(p.begin(),p.end());
        vector<int> out;
        for(int i=0;i<m-n;++i){
            string a=s.substr(i,n);
            sort(a.begin(),a.end());
            if(a==p) out.push_back(i);
        }

        return out;
    }
};

//滑动窗口
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = s.size();
		if(n==0||p.empty()) return {};
		unordered_map<char, int> need, window;
		//for (char i : p) ++need[p[i]];
		for(int i=0;i<p.size();++i) ++need[p[i]];

		int left = 0, right = 0, vaild = 0;
		vector<int> out;
		while (right < n) {
			char c = s[right];
			++right;
			if (need.count(c)) {
				++window[c];
				if (window[c] == need[c]) ++vaild;
			}

			//因为这里是while循环，而且把++right放在了开头，也就是说right的实际值比当前使用的值大一，所以这里是p.size()
            //这里改成if (right - left == p.size()) 也可以。
            while (right - left >= p.size()) {
				char d = s[left];
                //注意这里一定要用need.size()而不是p.size()
                //考虑“baa”，“aa”，当符合条件时，vaild是1，而p.size()是2
				if (vaild == need.size()) out.push_back(left);
                ++left;
				if (window.count(d)) {
					if (window[d] == need[d]) --vaild;
					--window[d];
				}
			}
		}
		return out;
	}
};