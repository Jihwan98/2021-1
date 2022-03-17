#include <iostream>
#include "Geometric.h"
#include "circle.h"
#include "rect.h"
using namespace std;
int main() {
	Geometric g;
	Circle c1;
	cout << c1.toString() << endl;
	cout << c1.getColor() << endl;
	Circle c2(55, "blue", true);
	cout << c2.toString() << endl;
	cout << c2.getColor() << endl;
	cout << c2.getRadius() << endl;
	Rect r1;
	cout << r1.toString() << endl;
	cout << r1.getColor() << endl;
	Rect r2(10, 100, "yellow", true);
	cout << r2.toString() << endl;
	cout << r2.getColor() << endl;
	cout << r2.getWidth() << endl;
	cout << r2.getHeight() << endl;
}