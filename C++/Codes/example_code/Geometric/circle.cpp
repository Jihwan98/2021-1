#include <iostream>
#include "circle.h"
using namespace std;

// class�� ���ǿ� class�� implementation �и��� ����
// class ���ǿ��� member ���� member �Լ��� proto type�� ���´�.
// class implementation ��Ʈ�� ��� �Լ��� �����Ѵ�.

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
Circle::Circle(double r, const string& _color, bool _filled) 
	:Geometric(_color, _filled)
{
	cout << "circle ���� �ִ� ������" << endl;
	radius = r;
}
Circle::~Circle() {
	cout << "circle �Ҹ���" << endl;
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
	return "���� circle ��ü�Դϴ�.";
}