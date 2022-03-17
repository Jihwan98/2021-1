#include <iostream>
#include "circle.h"
using namespace std;

int main() {
	Circle obj(50);
	cout << "address of obj : " << &obj << endl;
	obj.showYourself();

	// ���� ��ü �迭 static binding
	Circle A[3] = { Circle(5), Circle(15), Circle(25) };
	Circle* p = A;
	cout << "sizeof(Circle): " << sizeof(Circle) << endl;
	cout << "p: " << p << " "<< "p + 1: " << p + 1 << endl;

	// ���� ��ü �迭 dynamic binding
	// ����ڿ��� ���� ��ü �迭�� ũ�⸦ �����.
	// �� ũ�⿡ ���߾� ���� ��ü �迭�� �����Ѵ�.
	// ����ڿ��� �� Circle�� radius�� ���� �����Ѵ�.
	// �� Circle�� ������ ����ϰ�, ������ ũ�Ⱑ 100�� 200������ ������ ����Ѵ�.
	int n; 
	double radius;
	cout << "�� ��? : ";
	cin >> n;
	Circle* pArray = new Circle[n];
	for (int i = 0; i < n; i++) {
		cout << i << " ��° radius : ";
		cin >> radius;
		pArray[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		cout << i << " ��° ���� : " << pArray[i].getArea() << endl;
		if (pArray[i].getArea() >= 100 && pArray[i].getArea() <= 200) {
			count++;
		}
	}
	cout << "100 ~ 200 �� ���� ���� : " << count << endl;
	return 0;
}