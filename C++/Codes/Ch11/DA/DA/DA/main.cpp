#include <iostream>
#include "DA.h"
using namespace std;

void print(DA d);

int main() {
	DA a;
	a.ShowYourSelf();
	cout << "a.ptr: " << a.ptr << endl;
	DA b(5);
	// b.arr ��Ҹ� �Է¹޴´�.
	for (int i = 0; i < b.size; i++) {
		cout << "�Է�: ";
		cin >> b.ptr[i];
	}
	cout << endl;
	b.ShowYourSelf();
	cout << "b.ptr = " << b.ptr << endl;
	print(b);
	DA c(b);
	c.ShowYourSelf();
	cout << "c.ptr: " << c.ptr << endl;
	print(c);
	a = b;
	a.ShowYourSelf();
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