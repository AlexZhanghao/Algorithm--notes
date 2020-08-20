#include <iostream>

using namespace std;

class helper {
public:
	helper() :count(1) {};
	~helper() {};
	int count;
};

template<class T>
class mySharedptr {
public:
	mySharedptr(T* p) :m_ptr(p) { ph = new helper; }

	//拷贝构造函数
	mySharedptr(mySharedptr& sp) :m_ptr(sp.m_ptr), ph(sp.ph) {
		++ph->count;
	}

	~mySharedptr() { deconstruct(); }

	void deconstruct() {
		if (ph->count == 1) {   //引用计数为1表示只有一个对象使用指针指向的内存块了		
			delete m_ptr;
			delete ph;
		}

		--ph->count;
	}

	T& operator*() { return *m_ptr; }

	T* operator->() { return m_ptr; }

	//重载运算符=
	mySharedptr& operator = (const mySharedptr& sp) {
		++sp.ph->count;
		deconstruct();  //相当于先删掉左值,然后再通过右值赋值.
		m_ptr = sp.m_ptr;
		ph = sp.ph;
		return *this;
	}

	int getcount() {
		return ph->count;
	}

private:
	T* m_ptr; //被封装的指针
	helper* ph;   //引用计数,表示有多少个智能指针对象拥有m_ptr指向的内存块
};

int main() {
	int *a = new int(1);
	int *b = new int(2);
	mySharedptr<int> sptr1(a);
	{
		mySharedptr<int> sptr2(sptr1);
		mySharedptr<int> sptr3(b);
        cout << *sptr1 << endl;
        cout << *sptr2 << endl;
        cout << *sptr3 << endl;
        
        cout << "strat test!!!"  << endl;
		cout << sptr1.getcount() << endl;//2
		cout << sptr2.getcount() << endl;//2
		cout << sptr3.getcount() << endl;//1

		sptr2 = sptr3;
		cout << sptr1.getcount() << endl;//1
		cout << sptr2.getcount() << endl;//2
		cout << sptr3.getcount() << endl;//2
	}
	cout << sptr1.getcount() << endl;//1
	getchar();
	return 0;
}