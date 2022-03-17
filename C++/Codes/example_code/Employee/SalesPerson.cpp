#include <iostream>
#include "SalesPerson.h"
using namespace std;

Sales::Sales()
	:Employee()
{
	cout << "Sales con without argument" << endl;
	basicsalary = 0; earning = 0;
}
Sales::Sales(int _basicsalary, int _earning, const string _name)
	: Employee(_name)
{
	cout << "Sales con with argument" << endl;
	basicsalary = _basicsalary; earning = _earning;
}
Sales::Sales(const Sales& s)
	: Employee(s)
{
	cout << "Sales Copy con" << endl;
	basicsalary = s.basicsalary; earning = s.earning;
}
Sales::~Sales() {
	cout << "Sales decon" << endl;
}
int Sales::getBasicsalary() {
	return basicsalary;
}
void Sales::setBasicsalary(int _basicsalary) {
	basicsalary = _basicsalary;
}
int Sales::getEarning() {
	return earning;
}
void Sales::setEarning(int _earning) {
	earning = _earning;
}
int Sales::getPay() {
	return (basicsalary + earning * 0.2);
}