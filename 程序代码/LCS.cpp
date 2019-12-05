#include<iostream>
#include<vector>

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}

using namespace std;

void LCSLength(int *X, int *Y, int m, int n, vector<int>& LCS) {
	//int m = 0, n = 0;
	//GET_ARRAY_LEN(X, m);
	//GET_ARRAY_LEN(Y, n);

	vector<int> b;
	int **c = new int *[m + 1];
	for (int i = 0; i < m + 1; ++i) {
		c[i] = new int[n+1];
	}

	for (int i = 0; i < m + 1; ++i) {
		c[i][0] = 0;
	}
	for (int j = 0; j < n + 1; ++j) {
		c[0][j] = 0;
	}

	for (int i = 1; i < m + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (X[i] == Y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] > c[i][j - 1] || c[i - 1][j] == c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}

	for (int i = 0; i < m + 1; ++i) {
		cout << c[i][0] << "    " << c[i][1] << "    " << c[i][2] << "    " << c[i][3] << "    " << c[i][4] << "    " << c[i][5] << "    " << c[i][6] << "    " << endl;
	}

	int p = m , q = n ;
	while (p > 0 && q > 0) {
		if (c[p - 1][q - 1] <c[p][q]&& c[p - 1][q] < c[p][q] && c[p - 1][q - 1] < c[p][q]) {
			b.push_back(X[p-1]);
			p--;
			q--;
		}
		else if (c[p][q - 1] > c[p - 1][q]) {
			q--;
		}
		else {
			p--;
		}
	}

	//for (int i = 0; i < m + 1; ++i) {
	//	delete[] c[i];
	//}
	//delete[] c;

	int k = b.size();
	for (int i = 0; i < k; ++i) {
		LCS.push_back(b[k - i - 1]);
	}
}

int main() {
	int X[7] = { 1,2,3,2,4,1,2 };
	int Y[6] = { 2,4,3,1,2,1 };
	vector<int> LCS;
	LCSLength(X, Y, 7, 6, LCS);
	for (int i = 0; i < LCS.size(); ++i) {
		cout << LCS[i] << endl;
	}

	system("pause");
	return 0;
}