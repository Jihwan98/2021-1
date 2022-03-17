#include <iostream>
using namespace std;
// class�� ���ǿ� class�� implementation �и��� ����
// class ���ǿ��� member ����, member �Լ��� proto type �� ���´�.
// class implementation ��Ʈ�� ��� �Լ��� �����Ѵ�.
class Circle {
public:
	double radius;
	Circle();
	Circle(double r);
	double getArea();
};
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
int main() {
	cout << sizeof(Circle) << endl;
	Circle c1;
	cout << sizeof(c1) << endl;
	cout << "address of c1 : " << &c1 << endl;
	cout << "c1.radius : " << c1.radius << endl;
	cout << "c1 ���� : " << c1.getArea() << endl;
	// Circle c2(); // warning ������Ÿ�� �Լ�
	Circle c3(5);
	cout << "address of c3 : " << &c3 << endl;
	cout << "c3 ���� : " << c3.getArea() << endl;
	c1 = c3; // assignment
	cout << "c1.radius : " << c1.radius << endl;

	return 0;
}