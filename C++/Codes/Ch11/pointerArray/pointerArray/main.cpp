#include <iostream>
using namespace std;

int main() {
	double a = 58.2, b = 23.4, c = 72.3;
	double* K[3];
	K[0] = &a; // *K = &a;
	*(K + 1) = &b;
	K[2] = &c; // *(K+2) = &c;

	for (int i = 0; i < 3; i++) {
		// 배열의 요소 값을 보고 싶고, 이 요소를 dereferencing 해서 a, b, c 의값을 보고싶다.
		cout << K[i] << " " << *K[i] << endl;
		cout << *(K + i) << " " << **(K + i) << endl;
	}

	return 0;
}