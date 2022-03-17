#include <iostream>
#include "circle.h"
using namespace std;

void printCircleByVal(Circle c);
int main() {
	cout << "��ü�� ���� : " << Circle::getNumOfObjs() << endl;
	Circle c1;
	Circle c2(5);
	cout << "��ü�� ���� : " << Circle::getNumOfObjs() << endl;
	printCircleByVal(c2);
	Circle pizza(25);
	cout << "��ü�� ���� : " << Circle::getNumOfObjs() << endl;
	cout << "pizza.getArea(): " << pizza.getArea() << endl;
	// �����ڰ� �������� �� �� �Ҹ��� ���°�, �Ҹ��ڰ� �� �� �Ҹ��� ���°�.

	return 0;
}
void printCircleByVal(Circle c) {
	cout << "&c = " << &c << endl;
	cout << "c.getArea = " << c.getArea() << endl;
	Circle apple;
	Circle pear(apple);
	cout << "��ü�� ���� : " << Circle::getNumOfObjs() << endl;
}