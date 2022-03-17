#include <iostream>
#include "Point.h"
using namespace std;
Point::Point() {
	x = 0;
	y = 0;
	cout << "인자 없는 생성자" << endl;
}
Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
	cout << "인자 있는 생성자" << endl;
}
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	cout << "복사 생성자" << endl;
}
Point::~Point() {
	cout << "소멸자" << endl;
}
void Point::SetX(int _x) {
	x = _x;
}
void Point::SetY(int _y) {
	y = _y;
}
int Point::GetX() const {
	return x;
}
int Point::GetY() const {
	return y;
}
void Point::Print() const {
	cout << "(" << x << ", " << y << ")" << endl;
}