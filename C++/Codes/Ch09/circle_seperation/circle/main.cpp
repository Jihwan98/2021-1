#include <iostream>
#include "circle.h"
using namespace std;

int main() {
	cout << sizeof(Circle) << endl;
	Circle c1;
	cout << sizeof(c1) << endl;
	cout << "address of c1 : " << &c1 << endl;
	cout << "c1.radius : " << c1.radius << endl;
	cout << "c1 ���� : " << c1.getArea() << endl;
	// Circle c2(); // warning ������Ÿ�� �Լ�
	Circle c3(5);
	cout << "address of c3 : " << &c3 << endl;
	cout << "c3 ���� : " << c3.getArea() << endl;
	c1 = c3; // assignment
	cout << "c1.radius : " << c1.radius << endl;

	return 0;
}