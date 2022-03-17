#include <iostream>
#include "charstack.h"
using namespace std;

int main() {
	int n;
	CharStack s1(20);
	s1.Push('A');
	s1.Push('B');
	s1.Push('C');
	n = s1.getTopIdx();
	for (int i = 0; i <= n; i++) {
		cout << s1.Pop() << " ";
	}
	cout << endl;
	return 0;
}