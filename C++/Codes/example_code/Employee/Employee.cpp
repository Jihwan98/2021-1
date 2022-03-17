#include <iostream>
#include "Employee.h"
using namespace std;
Employee::Employee() {
	cout << "Employee con without arg" << endl;
	name = "noname";
}
Employee::Employee(const string& _name) {
	cout << "Employee con with arg" << endl;
	name = _name;
}
Employee::Employee(const Employee& e) {
	cout << "Employee Copy con" << endl;
	name = e.name;
}
Employee::~Employee() {
	cout << "Employee decon" << endl;
}
string Employee::getName() {
	return name;
}
void Employee::setName(const string& _name) {
	name = _name;
}
//int Employee::getPay() {
//	return 0;
//}