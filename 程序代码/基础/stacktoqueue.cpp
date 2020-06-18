#include<iostream>
#include<stack>

using namespace std;

//一定要注意检查栈中是否为空
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
		front_num = 0;
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (s1.empty()) front_num = x;

		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (empty()) return -1;
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int out = s2.top();
		s2.pop();
		if(!s2.empty()) front_num = s2.top();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return out;
	}

	/** Get the front element. */
	int peek() {
		if (s1.empty()) return false;
		return front_num;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty();
	}

private:
	int front_num;
	stack<int> s1, s2;
};