#include <iostream>
#include "Point.h"
using namespace std;
Point::Point() {
	x = 0;
	y = 0;
	cout << "���� ���� ������" << endl;
}
Point::Point(int _x, int _y) {
	x = _x;
	y = _y;
	cout << "���� �ִ� ������" << endl;
}
Point::Point(const Point& p) {
	x = p.x;
	y = p.y;
	cout << "���� ������" << endl;
}
Point::~Point() {
	cout << "�Ҹ���" << endl;
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