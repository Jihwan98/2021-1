#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee() {
	cout << "Employee ���� ���� ������" << endl;
	name = "";
}
Employee::Employee(const string& _name) {
	cout << "Employee ���� �ִ� ������" << endl;
	name = _name;
}
Employee::Employee(const Employee& e) {
	cout << "Employee ���� ������" << endl;
	name = e.name;
}
Employee::~Employee() {
	cout << "Employee �Ҹ���" << endl;
}
void Employee::setName(const string& _name) {
	name = _name;
}
string Employee::getName() {
	return name;
}
//int Employee::getPay() {
//	return 0;
//}