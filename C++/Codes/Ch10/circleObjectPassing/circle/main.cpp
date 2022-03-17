#include <iostream>
#include "circle.h"
using namespace std;

void printCircleByVal(Circle c);
void printCircleByRef(Circle& c);
void printCircleByPtr(Circle* p);
int main() {
	Circle obj(5.5);
	cout << "&obj = " << &obj << endl;
	printCircleByVal(obj);
	printCircleByRef(obj);
	printCircleByPtr(&obj);

	return 0;
}
void printCircleByVal(Circle c) {
	cout << "&c = " << &c << endl;
	cout << "c.getArea = " << c.getArea() << endl;
}
void printCircleByRef(Circle& c) {
	cout << "&c = " << &c << endl;
	cout << "c.getArea = " << c.getArea() << endl;
}
void printCircleByPtr(Circle* p) {
	cout << "p = " << p << endl;
	cout << "&p = " << &p << endl;
	cout << "(*p).getArea = " << (*p).getArea() << endl;
	cout << "p->getArea = " << p->getArea() << endl;
}