#include <iostream>
#include <stdexcept>
using namespace std;
int main() {
	try {
		for (int i = 0; i < 100; i++) {
			int* p = new int[70000000]; // Error detected in new operator
			cout << i << "th array has been created" << endl;
		}
	}
	catch (bad_alloc& ex) { // Error handled in catch block
		cout << ex.what() << endl;
	}
	cout << "Execution continues..." << endl;
	return 0;
}