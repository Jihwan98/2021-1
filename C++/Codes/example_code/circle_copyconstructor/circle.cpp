#include <iostream>
#include "circle.h"
using namespace std;

// class�� ���ǿ� class�� implementation �и��� ����
// class ���ǿ��� member ���� member �Լ��� proto type�� ���´�.
// class implementation ��Ʈ�� ��� �Լ��� �����Ѵ�.

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