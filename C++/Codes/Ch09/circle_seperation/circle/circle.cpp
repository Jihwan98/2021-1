#include <iostream>
#include "circle.h"
using namespace std;

// class�� ���ǿ� class�� implementation �и��� ����
// class ���ǿ��� member ����, member �Լ��� proto type �� ���´�.
// class implementation ��Ʈ�� ��� �Լ��� �����Ѵ�.

Circle::Circle() { // scope resolution operator
	cout << "no-arg constructor" << endl;
	radius = 1;

}
Circle::Circle(double r) {
	cout << "arg constructor" << endl;
	radius = r;
}
double Circle::getArea() {
	return radius * radius * 3.14;
}