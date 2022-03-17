#include <iostream>
#include "circle.h"
using namespace std;

// class의 정의와 class의 implementation 분리할 예정
// class 정의에는 member 변수 member 함수의 proto type만 적는다.
// class implementation 파트에 멤버 함수를 정의한다.

Circle::Circle() { // scope resolution operator
	cout << "no-arg constructor" << endl;
	radius = 1;
}
Circle::Circle(double r) {
	cout << "arg constructor" << endl;
	radius = r;
}
Circle::Circle(const Circle& obj) {
	cout << "copy constructor" << endl;
	radius = obj.radius;
}
Circle::~Circle() {
	cout << "deconstructor" << endl;
}
double Circle::getArea() {
	return radius * radius * 3.14;
}

double Circle::getRadius() {
	return radius;
}
void Circle::setRadius(double r) {
	if (r >= 0)
		radius = r;
	else
		radius = 0;
}