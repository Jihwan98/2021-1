#include <iostream>
#include "point.h"
using namespace std;
Point::Point() {
	cout << "인자 없는 생성자" << endl;
	x = 0;
	y = 0;
}
Point::Point(int _x, int _y) {
	cout << "인자 있는 생성자" << endl;
	x = _x;
	y = _y;
}
Point::Point(const Point& p) {
	cout << "복사 생성자" << endl;
	x = p.x;
	y = p.y;
}
Point::~Point() {
	cout << "소멸자" << endl;
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