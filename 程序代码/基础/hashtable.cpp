#include<iostream>
#include<vector>
#include<list>

using namespace std;

class myHashtable {
public:
	myHashtable(int x) {
		len = x;
		for (int i = 0; i < len; ++i) {
			list<int> a;
			elem.push_back(a);
		}
	}
	~myHashtable() {}

	int hash(int key) {
		return key % len;
	}

	void insert(int x) {
		int addr = hash(x);
		elem[addr].push_back(x);
	}

	bool search(int x) {
		int addr = hash(x);
		for (auto i = elem[addr].begin(); i != elem[addr].end(); ++i) {
			if (*i == x) return true;
		}

		return false;
	}

    bool erase(int x){
        int addr = hash(x);
        for (auto i = elem[addr].begin(); i != elem[addr].end(); ++i) {
			if (*i == x){
                elem[addr].erase(i++);
                return true;
            }
		}

        return false;
    }

private:
	vector<list<int>> elem;
	int len;
};

int main() {
	myHashtable a(10);
	for (int i = 0; i < 12; ++i) {
		a.insert(i);
	}
	cout << a.search(12) << endl;
	cout << a.search(11) << endl;
	cout << a.search(0) << endl;
	
	getchar();
	return 0;
}