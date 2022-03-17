#ifndef TEMP_H
#define TEMP_H
#include "Employee.h"
class Temp : public Employee {
protected:
	int hourlywage;
	int hrs;
public:
	Temp();
	Temp(int _hourlywage, int _hrs, string _name);
	Temp(const Temp& t);
	~Temp();
	int gethourlyWage();
	void sethourlyWage(int _hourlywage);
	int gethrs();
	void sethrs(int _hrs);
	int getPay();
};
#endif