#ifndef PERMANENT_H
#define PERMANENT_H
#include "Employee.h"
class Permanent : public Employee {
protected:
	int salary; // monthly salary
public:
	Permanent();
	Permanent(int _salary, string _name);
	Permanent(const Permanent& p);
	~Permanent();
	int getSalary();
	void setSalary(int _salary);
	int getPay();
};
#endif