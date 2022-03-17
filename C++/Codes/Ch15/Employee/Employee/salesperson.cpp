#include <iostream>
#include "salesperson.h"
using namespace std;

SalesPerson::SalesPerson() 
	:Employee()
{
	cout << "SalesPerson 인자 없는 생성자" << endl;
	basicsalary = 0;
	profit = 0;
}
SalesPerson::SalesPerson(int _basicsalary, int _profit, const string& _name)
	:Employee(_name)
{
	cout << "SalesPerson 인자 있는 생성자" << endl;
	basicsalary = _basicsalary;
	profit = _profit;
}
SalesPerson::SalesPerson(const SalesPerson& s) 
	:Employee(s)
{
	cout << "SalesPerson 복사 생성자" << endl;
	basicsalary = s.basicsalary;
	profit = s.profit;
}
SalesPerson::~SalesPerson() {
	cout << "SalesPerson 소멸자" << endl;
}
void SalesPerson::setBasicsalary(int _basicsalary) {
	basicsalary = _basicsalary;
}
void SalesPerson::setProfit(int _profit) {
	profit = _profit;
}
int SalesPerson::getProfit() {
	return profit;
}
int SalesPerson::getPay() {
	return basicsalary + profit * 0.2;
}