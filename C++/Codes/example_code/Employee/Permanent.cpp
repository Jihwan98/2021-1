#include <iostream>
#include "Permanent.h"
using namespace std;
Permanent::Permanent()
	:Employee()
{
	cout << "Permanent con without argument" << endl;
	salary = 0;
}
Permanent::Permanent(int _salary, string _name)
	: Employee(_name)
{
	cout << "Permanent con with argument" << endl;
	salary = _salary;
}
Permanent::Permanent(const Permanent& p)
	: Employee(p)
{
	cout << "Permanent con with argument" << endl;
	salary = p.salary;
}
Permanent::~Permanent()
{
	cout << "Permanent decon" << endl;
}
int Permanent::getSalary() {
	return salary;
}
void Permanent::setSalary(int _salary) {
	salary = _salary;
}
int Permanent::getPay() {
	return salary;
}