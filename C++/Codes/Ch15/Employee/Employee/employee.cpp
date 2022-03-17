#include <iostream>
#include "employee.h"
using namespace std;

Employee::Employee() {
	cout << "Employee 인자 없는 생성자" << endl;
	name = "";
}
Employee::Employee(const string& _name) {
	cout << "Employee 인자 있는 생성자" << endl;
	name = _name;
}
Employee::Employee(const Employee& e) {
	cout << "Employee 복사 생성자" << endl;
	name = e.name;
}
Employee::~Employee() {
	cout << "Employee 소멸자" << endl;
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