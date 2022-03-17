#include <iostream>
#include "circle.h"
using namespace std;

int main() {
	Circle obj(50);
	cout << "address of obj : " << &obj << endl;
	obj.showYourself();

	// 정적 개체 배열 static binding
	Circle A[3] = { Circle(5), Circle(15), Circle(25) };
	Circle* p = A;
	cout << "sizeof(Circle): " << sizeof(Circle) << endl;
	cout << "p: " << p << " "<< "p + 1: " << p + 1 << endl;

	// 동적 개체 배열 dynamic binding
	// 사용자에게 동적 개체 배열의 크기를 물어본다.
	// 그 크기에 맞추어 동적 개체 배열을 생성한다.
	// 사용자에게 각 Circle의 radius를 물어 저장한다.
	// 각 Circle의 면적을 출력하고, 면적의 크기가 100과 200사이의 개수를 출력한다.
	int n; 
	double radius;
	cout << "몇 개? : ";
	cin >> n;
	Circle* pArray = new Circle[n];
	for (int i = 0; i < n; i++) {
		cout << i << " 번째 radius : ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		cout << i << " 번째 면적 : " << pArray[i].getArea() << endl;
		if (pArray[i].getArea() >= 100 && pArray[i].getArea() <= 200) {
			count++;
		}
	}
	cout << "100 ~ 200 의 면적 개수 : " << count << endl;
	return 0;
}