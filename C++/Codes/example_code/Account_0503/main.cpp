#include <iostream>
#include "account.h"
using namespace std;

int main() {
	Account a1;
	a1.ShowAllData();
	cout << "(void*)(a1.getName())" << (void*)(a1.getName()) << endl;
	Account a2(1, 1000, "Alpha Go");
	a2.ShowAllData();
	cout << "(void*)(a2.getName())" << (void*)(a2.getName()) << endl;
	Account a3(a2);
	a3.ShowAllData();
	cout << "(void*)(a3.getName())" << (void*)(a3.getName()) << endl;
	a1 = a2;
	a1.ShowAllData();
	cout << "(void*)(a1.getName())" << (void*)(a1.getName()) << endl;
	return 0;
}
// OOP�� �����ϴ� �߿��� �� ���� ����
// abstraction, encapsulation, inheritance, polymorphism
// 15���� �б� �����Ѵ�.