#include <iostream>
#include "temporary.h"
using namespace std;

Temporary::Temporary() 
	:Employee()
{
	cout << "Temporary ���� ���� ������" << endl;
	hourlyWage = 0;
	hrs = 0;
}
Temporary::Temporary(int _hourlyWage, int _hrs, const string& _name)
	:Employee(_name)
{
	cout << "Temporary ���� �ִ� ������" << endl;
	hourlyWage = _hourlyWage;
	hrs = _hrs;
}
Temporary::Temporary(const Temporary& t) 
	:Employee(t)
{
	cout << "Temporary ���� ������" << endl;
	hourlyWage = t.hourlyWage;
	hrs = t.hrs;
}
Temporary::~Temporary() {
	cout << "Temporary �Ҹ���" << endl;
}
void Temporary::setHourlyWage(int _hourlyWage) {
	hourlyWage = _hourlyWage;
}
void Temporary::setHrs(int _hrs) {
	hrs = _hrs;
}
int Temporary::getHrs() {
	return hrs;
}
int Temporary::getPay() {
	return hourlyWage * hrs;
}