#include <iostream>
using namespace std;
int quotient(int n1, int n2);
int main() {
	cout << "Enter two integers: ";
	int number1, number2;
	cin >> number1 >> number2;
	try {
		int res = quotient(number1, number2);
		cout << "Quotient = " << res << endl;
	}
	catch (int ex) { // Error handling
		cout << "Exception from function: an integer " << ex << " cannot be divided by 0" << endl;
	}
	cout << "Execution continues..." << endl;
	return 0;
}
int quotient(int n1, int n2) {
	if (n2 == 0) { // Error detection
		throw n1;
	}
	return n1 / n2;
}