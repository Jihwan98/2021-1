#include <iostream>
#include "permanent.h"
using namespace std;
Permanent::Permanent()
	:Employee()
{
	cout << "Permanent 인자 없는 생성자" << endl;
	pay = 0;
}
Permanent::Permanent(int _pay, const string& _name) 
	:Employee(_name)
{
	cout << "Permanent 인자 있는 생성자" << endl;
	pay = _pay;
}
Permanent::Permanent(const Permanent& p) 
	:Employee(p)
{
	cout << "Permanent 복사 생성자" << endl;
	pay = p.pay;
}
Permanent::~Permanent() {
	cout << "Permanent 소멸자" << endl;
}
void Permanent::setPay(int _pay) {
	pay = _pay;
}
int Permanent::getPay() {
	return pay;
}