#include <iostream>
#include "point.h"
using namespace std;
Point::Point() {
	cout << "���� ���� ������" << endl;
	x = 0;
	y = 0;
}
Point::Point(int _x, int _y) {
	cout << "���� �ִ� ������" << endl;
	x = _x;
	y = _y;
}
Point::Point(const Point& p) {
	cout << "���� ������" << endl;
	x = p.x;
	y = p.y;
}
Point::~Point() {
	cout << "�Ҹ���" << endl;
}
void Point::setX(int _x) {
	x = _x;
}
void Point::setY(int _y) {
	y = _y;
}
int Point::getX() const {
	return x;
}
int Point::getY() const {
	return y;
}
void Point::Print() const {
	cout << "(" << x << ", " << y << ")" << endl;
}