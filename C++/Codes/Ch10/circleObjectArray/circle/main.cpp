#include <iostream>
#include "circle.h"
using namespace std;

int main() {
	Circle pizza(30);
	Circle* p = &pizza;
	cout << "(*p).getArea : " << (*p).getArea() << endl;
	cout << "p->getArea : " << p->getArea() << endl;
	cout << "p: " << p << endl;
	cout << "p + 3" << p + 3 << endl;
	Circle A[3];
	Circle B[3] = { Circle(10), Circle(20), Circle(30) };
	p = B;
	// B array의 element의 radius를 각각 1, 2, 3 으로 바꾸어라
	// 0번째 요소 : index expression with array name 한 가지 
	// 1번째 요소 : pointer expression with array name 두 가지
	// 2번째 요소 : pointer expression with pointer, p 두 가지
	B[0].setRadius(1);
	(*(B + 1)).setRadius(2);
	(B + 1)->setRadius(2);
	(*(p + 2)).setRadius(3);
	(p + 2)->setRadius(3);
	// for loop를 통해서 다섯 가지 방법으로 면적을 보이기.
	for (int i = 0; i < 3; i++) {
		cout << B[i].getArea() << "\t" << (B + i)->getArea() << "\t" << (*(B + i)).getArea() << "\t";
		cout << (p + i)->getArea() << "\t" << (*(p + i)).getArea() << "\n";
	}
	return 0;
}