#include <iostream>
#include "DA.h"
using namespace std;
void print(DA d);
int main() {
	DA a;
	cout << "a.ptr: " << a.ptr << endl;
	DA b(5);
	// b.ptr 요소를 입력받는다.
	for (int i = 0; i < b.size; i++) {
		cout << "입력: ";
		cin >> b.ptr[i];
	}
	cout << endl;
	cout << "b.ptr = " << b.ptr << endl;
	print(b);
	DA c(b);
	cout << "c.ptr: " << c.ptr << endl;
	print(c);
	a = b;
	cout << "a.ptr: " << a.ptr << endl;
	print(a);
	return 0;
}
void print(DA d) {
	for (int i = 0; i < d.size; i++) {
		cout << d.ptr[i] << " ";
	}
	cout << endl;
}