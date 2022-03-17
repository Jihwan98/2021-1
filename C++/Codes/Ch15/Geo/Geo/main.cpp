#include <iostream>
#include "geometric.h"
#include "circle.h"
#include "rect.h"
using namespace std;
void func(Geometric g) {
	cout << "I'm in func()" << endl;
	cout << g.toString() << " " << g.getColor() << endl;
}
int main() {
	Geometric g3("blue", false);
	//Geometric g4(g3);
	func(g3);
	Circle c3(50, "orange", true);
	//Circle c4(c3);
	func(c3);

	/*Geometric g;
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
	cout << r2.getHeight() << endl;*/
	return 0;
}