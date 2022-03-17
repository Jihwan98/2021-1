#ifndef SALESPERSON_H
#define SALESPERSON_H
#include "employee.h"
class SalesPerson :public Employee {
protected:
	int basicsalary, profit;
public:
	SalesPerson();
	SalesPerson(int _basicsalary, int _profit, const string& _name);
	SalesPerson(const SalesPerson& s);
	~SalesPerson();
	void setBasicsalary(int _basicsalary);
	void setProfit(int _profit);
	int getProfit();
	int getPay();
};

#endif // !SALESPERSON_H
