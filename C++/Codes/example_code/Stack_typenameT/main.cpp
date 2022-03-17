#include <iostream>
#include "Stack.h"
#include "Geometric.h"
using namespace std;
int main() {
	int n;
	Stack<char> s1(20);
	s1.Push('A');
	s1.Push('B');
	s1.Push('C');
	n = s1.getTopIdx();
	for (int i = 0; i <= n; i++) {
		cout << s1.Pop() << " ";
	}
	cout << endl;

	Stack<int> s2(20);
	s2.Push(1);
	s2.Push(2);
	s2.Push(3);
	n = s2.getTopIdx();
	for (int i = 0; i <= n; i++) {
		cout << s2.Pop() << " ";
	}
	cout << endl;

	Stack<Geometric> s3(20);
	s3.Push(Geometric("blue", 1, 1));
	s3.Push(Geometric("red", 3, 3));
	s3.Push(Geometric("yellow", 5, 5));
	s3.Push(Geometric("green", 7, 7));
	Geometric g;
	n = s3.getTopIdx();
	for (int i = 0; i <= n; i++) {
		g = s3.Pop();
		g.draw();
	}
	cout << endl;
	return 0;
}