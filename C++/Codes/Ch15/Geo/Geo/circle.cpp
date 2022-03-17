#include <iostream>
#include "circle.h"
using namespace std;

// class�� ���ǿ� class�� implementation �и��� ����
// class ���ǿ��� member ����, member �Լ��� proto type �� ���´�.
// class implementation ��Ʈ�� ��� �Լ��� �����Ѵ�.

Circle::Circle()
	:Geometric()
{ // scope resolution operator
	cout << "Circle no-arg constructor" << endl;
	radius = 1;

}
Circle::Circle(double r) 
	:Geometric()
{
	cout << "Circle arg constructor" << endl;
	radius = r;
}
Circle::Circle(double r, const string& _color, bool _filled) 
	:Geometric(_color, _filled)
{
	cout << "Circle ���� �ִ� ������" << endl;
	radius = r;
}
Circle::Circle(const Circle& c) 
	:Geometric(c)
{
	cout << "Circle ���� ������" << endl;
	radius = c.radius;
}
Circle::~Circle() {
	cout << "Cricle �Ҹ���" << endl;
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
	return "���� Circle ��ü�Դϴ�.";
}