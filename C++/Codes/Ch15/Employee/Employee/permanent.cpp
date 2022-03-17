#include <iostream>
#include "permanent.h"
using namespace std;
Permanent::Permanent()
	:Employee()
{
	cout << "Permanent ���� ���� ������" << endl;
	pay = 0;
}
Permanent::Permanent(int _pay, const string& _name) 
	:Employee(_name)
{
	cout << "Permanent ���� �ִ� ������" << endl;
	pay = _pay;
}
Permanent::Permanent(const Permanent& p) 
	:Employee(p)
{
	cout << "Permanent ���� ������" << endl;
	pay = p.pay;
}
Permanent::~Permanent() {
	cout << "Permanent �Ҹ���" << endl;
}
void Permanent::setPay(int _pay) {
	pay = _pay;
}
int Permanent::getPay() {
	return pay;
}