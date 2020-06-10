#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<stack>

using namespace std;

//DFS解法
class Solution {
public:
    vector<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        // 寻找不合法半边括号的个数
        int left=0;
        int right=0;
        for(char i:s){
            if(i=='('){
                left++;
            }
            if(i==')'){
                if(left>0)left--;
                else right++;
            }
        }
        // 深度优先遍历，寻找题解
        // left与right为需要删除的数量
        dfs(s, 0, left, right);
        
        return ans;
    }
    void dfs(string s, int st, int l, int r){
        if(l==0&&r==0){
            if(check(s)){
                ans.push_back(s);
            }
            return;
        }
        for(int i=st;i<s.size();i++){
             // 去重
            if(i-1>=st&&s[i]==s[i-1])continue;
            if(l>0&&s[i]=='('){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l-1, r);
            }
            if(r>0&&s[i]==')'){
                dfs(s.substr(0, i)+s.substr(i+1, s.size()-i-1), i, l, r-1);
            }
        }
    }
    // 检验合法性
    bool check(string s){
        int cnt=0;
        for(char i:s){
            if(i=='('){
                cnt++;
            }
            if(i==')'){
                cnt--;
                if(cnt<0)return false;
            }
        }
        return cnt==0;
    }
};

//BFS解法，在执行"())((((((((((b))("时报错
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		int n = s.size();
		if (n ==0 ) return {""};

		queue<string> q;
		q.push(s);

		unordered_set<string> us;
		vector<string> out;

		while (!q.empty()) {
			int qsize = q.size();
			for (int i = 0; i < qsize; ++i) {
				string cur = q.front();
				q.pop();				
				if (isValid(cur)) out.push_back(cur);
				for (int j = 0; j < n; ++j) {
					if (cur[j] == '(' || cur[j] == ')') {
						string a = cur;
						a.erase(j, 1);						
						if (us.count(a)) continue;
						else{
                            us.insert (a);
                            q.push(a);
                        }
					}
				}
			}
			if (!out.empty()) return out;
		}
		return {""};
	}

    bool isValid(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') {
                cnt++;
            } else if (c == ')') {
                cnt--;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};



