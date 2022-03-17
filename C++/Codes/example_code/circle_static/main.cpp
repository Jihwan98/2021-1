#include <iostream>
#include "circle.h"
using namespace std;

void printCircleByVal(Circle c);
int main() {
	cout << "��ü�� ����: " << Circle::getNumOfObjs() << endl;
	Circle c1;
	Circle c2(5);
	cout << "��ü�� ����: " << Circle::getNumOfObjs() << endl;
	printCircleByVal(c2);
	cout << "��ü�� ����: " << Circle::getNumOfObjs() << endl;
	Circle pizza(25);
	cout << "��ü�� ����: " << Circle::getNumOfObjs() << endl;
	cout << "pizza.getArea(): " << pizza.getArea() << endl;
	// �����ڰ� �������� �� �� �Ҹ��� ������, �Ҹ��ڰ� �� �� �Ҹ��� ������
	return 0;
}
void printCircleByVal(Circle c) {
	cout << "&c: " << &c << endl;
	cout << "c.getArea(): " << c.getArea() << endl;
	Circle apple;
	Circle pear(apple);
	cout << "��ü�� ����: " << Circle::getNumOfObjs() << endl;
}

/*
arg constructor
&obj: 0113FB34
&c: 0113FA5C
c.getArea(): 94.985
&c: 0113FB34
c.getArea(): 94.985
p: 0113FB34
&p: 0113FA60
(*p).getArea(): 94.985
*/