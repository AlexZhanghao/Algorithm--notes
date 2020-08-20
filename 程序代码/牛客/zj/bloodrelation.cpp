//给定每个人的父母，判断两个人是否有血缘关系
//血缘关系的定义：有相同的祖先或A是B的祖先
//输入：
//1: [2, 3]
//4 : [2, 3]
//询问1, 4，答案：true
//询问2, 3，答案：false
//输入：
//1 : [2, 3]
//4 : [5, 6]
//询问1, 5，答案：false
//输入：
//1 : [2, 3]
//4 : [5, 6]
//7 : [1, 8]
//询问7, 3，答案：true

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>

using namespace std;

bool Find(int a, int b, unordered_map<int, pair<int, int>> &m) {
	vector<int> ap, bp;
	queue<int> aq, bq;
	aq.push(a);
	bq.push(b);
	while (!aq.empty()) {
		int cur = aq.front();
		aq.pop();
		if (m.count(cur)) {
			aq.push(m[cur].first);
			aq.push(m[cur].second);
		}
		else ap.push_back(cur);
	}

	while (!bq.empty()) {
		int cur = bq.front();
		bq.pop();
		if (m.count(cur)) {
			bq.push(m[cur].first);
			bq.push(m[cur].second);
		}
		else bp.push_back(cur);
	}

	sort(ap.begin(), ap.end());
	sort(bp.begin(), bp.end());

	int ptra = 0, ptrb = 0;
	while (ptra < ap.size() && ptrb < bp.size()) {
		if (ap[ptra] == bp[ptrb]) return true;
		else if (ap[ptra] < bp[ptrb]) ++ptra;
		else ++ptrb;
	}

	return false;
}

int getp(int i, vector<int>& book) {
	if (book[i] == i) return book[i];
	else {
		book[i] = getp(book[i],book);
		return book[i];
	}
}

void merge(int i,int j, vector<int>& book) {
	int p1 = getp(i, book);
	int p2 = getp(j, book);

	if (p1 != p2) {
		book[p2] = book[p1];
	}
}

//并查集解法
int main() {
	vector<vector<int>> relation = { {1,2,3},{4,5,6},{7,1,8} };
	vector<int> book(11,0);

	for (int i = 1; i < 11; ++i) book[i] = i;

	for (int i = 0; i < relation.size(); ++i) {
		for (int j = 1; j < 3; ++j) {
			merge(relation[i][0], relation[i][j], book);
		}
	}

	for (int i = 1; i < book.size(); ++i) getp(i, book);

	for (int i = 0; i < book.size(); ++i) {
		cout << book[i] << "  ";
	}
	cout << endl;

	getchar();
	return 0;
}