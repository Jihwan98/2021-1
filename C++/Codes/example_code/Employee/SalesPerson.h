#ifndef SALES_H
#define SALES_H
#include "Employee.h"
class Sales : public Employee {
protected:
	int basicsalary;
	int earning;
public:
	Sales();
	Sales(int _basicsalary, int _earning, const string _name);
	Sales(const Sales& s);
	~Sales();
	int getBasicsalary();
	void setBasicsalary(int _basicsalary);
	int getEarning();
	void setEarning(int _earning);
	int getPay();
};
#endif