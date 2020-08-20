#include<iostream>

using namespace std;

class myStack {
public:
	myStack(int x) {
		len = x;
		data = new int[len];
		top = -1;
		memset(data, 0, sizeof(data));
	}
	~myStack() {
		delete[]data;
	}

	bool push(int x) {
		if (top == len - 1) return false;
		++top;
		data[top] = x;

		return true;
	}

	bool pop() {
		if (top == -1) return false;
		--top;
		return true;
	}

	int Top() {
		return data[top];
	}

private:
	int len;
	int *data;
	int top;
};

int main() {
	myStack a(10);
	for (int i = 1; i < 11; ++i) {
		a.push(i);
	}
	for (int i = 0; i < 10; ++i) {
		cout << a.Top() << endl;
		a.pop();
	}
	
	getchar();
	return 0;
}