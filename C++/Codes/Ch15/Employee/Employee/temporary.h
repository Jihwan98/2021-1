#ifndef TEMPORARY_H
#define TEMPORARY_H
#include "employee.h"
class Temporary :public Employee {
protected:
	int hourlyWage, hrs;
public:
	Temporary();
	Temporary(int _hourlyWage, int _hrs, const string& _name);
	Temporary(const Temporary& t);
	~Temporary();
	void setHourlyWage(int _hourlyWage);
	void setHrs(int _hrs);
	int getHrs();
	int getPay();
};
#endif