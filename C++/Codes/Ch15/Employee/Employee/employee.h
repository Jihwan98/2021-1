#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
	string name;
public:
	Employee();
	Employee(const string& _name);
	Employee(const Employee& e);
	virtual ~Employee();
	void setName(const string& _name);
	string getName();
	virtual int getPay() = 0; // pure virtual, Employee becomes abstract class.
};

#endif 
