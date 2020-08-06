#include<iostream>
using namespace std;
 
struct X {};
void inner(const X&) {cout << "inner(const X&)" << endl;}
void inner(X&&) {cout << "inner(X&&)" << endl;}
template<typename T>
void outer(T&& t) {inner(forward<T>(t));}
 
int main()
{
	X a;
	outer(a);
	outer(X());
	inner(forward<X>(X()));
}
//inner(const X&)
//inner(X&&)
//inner(X&&)