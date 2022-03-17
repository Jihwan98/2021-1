#include <iostream>
#include "circle.h"
using namespace std;

// class의 정의와 class의 implementation 분리할 예정
// class 정의에는 member 변수 member 함수의 proto type만 적는다.
// class implementation 파트에 멤버 함수를 정의한다.

Circle::Circle()
	:Geometric()
{ // scope resolution operator
	cout << "circle no-arg constructor" << endl;
	radius = 1;
}
Circle::Circle(double r) 
	:Geometric()
{
	cout << "circle arg constructor" << endl;
	radius = r;
}
Circle::Circle(double r, const string& _color, int _x, int _y) 
	:Geometric(_color, _x, _y)
{
	cout << "circle 인자 있는 생성자" << endl;
	radius = r;
}
Circle::Circle(const Circle& c)
	:Geometric(c)
{
	cout << "circle 복사 생성자" << endl;
	radius = c.radius;
}
Circle::~Circle() {
	cout << "circle 소멸자" << endl;
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
double Circle::getPerimeter() {
	return 2 * radius * 3.14159;
}
double Circle::getDiameter() {
	return 2 * radius;
}
string Circle::toString() {
	return "나는 circle 객체입니다.";
}
void Circle::draw() {
	cout << "[Circle] Position = (" << x << ", " << y << "), Radius = " << radius << ", Color = " << color << endl;
}