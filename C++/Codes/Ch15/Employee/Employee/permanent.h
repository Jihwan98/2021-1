#ifndef PERMANENT_H
#define PERMANENT_H
#include "employee.h"
class Permanent :public Employee {
protected:
	int pay;
public:
	Permanent();
	Permanent(int _pay, const string& _name);
	Permanent(const Permanent& p);
	~Permanent();
	void setPay(int _pay);
	int getPay();
};

#endif