#include <iostream>
#include "salesperson.h"
using namespace std;

SalesPerson::SalesPerson() 
	:Employee()
{
	cout << "SalesPerson ���� ���� ������" << endl;
	basicsalary = 0;
	profit = 0;
}
SalesPerson::SalesPerson(int _basicsalary, int _profit, const string& _name)
	:Employee(_name)
{
	cout << "SalesPerson ���� �ִ� ������" << endl;
	basicsalary = _basicsalary;
	profit = _profit;
}
SalesPerson::SalesPerson(const SalesPerson& s) 
	:Employee(s)
{
	cout << "SalesPerson ���� ������" << endl;
	basicsalary = s.basicsalary;
	profit = s.profit;
}
SalesPerson::~SalesPerson() {
	cout << "SalesPerson �Ҹ���" << endl;
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