#include <iostream>
#include <stdexcept>
using namespace std;

int quotient(int n1, int n2);
int main() {
	cout << "Enter two integers: ";
	int num1, num2;
	cin >> num1 >> num2;
	try {
		int res = quotient(num1, num2);
		cout << "¸ò: " << res << endl;
	}
	catch (exception& ex) { // exception handling
		cout << ex.what() << endl;
	}
	cout << "Execution continues..." << endl;
	return 0;
}
int quotient(int n1, int n2) {
	if (n2 == 0) { // exception detection
		runtime_error e("Divisor cannot be zero");
		throw e; 
	}
	return n1 / n2;
}