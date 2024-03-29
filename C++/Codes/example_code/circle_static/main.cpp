#include <iostream>
#include "circle.h"
using namespace std;

void printCircleByVal(Circle c);
int main() {
	cout << "객체의 개수: " << Circle::getNumOfObjs() << endl;
	Circle c1;
	Circle c2(5);
	cout << "객체의 개수: " << Circle::getNumOfObjs() << endl;
	printCircleByVal(c2);
	cout << "객체의 개수: " << Circle::getNumOfObjs() << endl;
	Circle pizza(25);
	cout << "객체의 개수: " << Circle::getNumOfObjs() << endl;
	cout << "pizza.getArea(): " << pizza.getArea() << endl;
	// 생성자가 종류별로 몇 번 불리어 졌는지, 소멸자가 몇 번 불리어 졌는지
	return 0;
}
void printCircleByVal(Circle c) {
	cout << "&c: " << &c << endl;
	cout << "c.getArea(): " << c.getArea() << endl;
	Circle apple;
	Circle pear(apple);
	cout << "객체의 개수: " << Circle::getNumOfObjs() << endl;
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