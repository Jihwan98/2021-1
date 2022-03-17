#include <iostream>
#include <stdexcept>
using namespace std;
double getArea(double r);
int main() {
	cout << "Enter radius : ";
	double radius;
	cin >> radius;
	try {
		double res = getArea(radius);
		cout << "Area : " << res << endl;
	}
	catch (invalid_argument& ex) { 
		cout << ex.what() << endl;
	}
	cout << "Execution continues..." << endl;
	return 0;
}
double getArea(double r) {
	if (r < 0) {
		invalid_argument e("Radius cannot be negative");
		throw e;
	}
	return r * r * 3.14159;
}