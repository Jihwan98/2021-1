#include <iostream>
#include "Temporary.h"
using namespace std;
Temp::Temp()
	:Employee()
{
	cout << "Temp con without argument" << endl;
	hourlywage = 0;
	hrs = 0;
}
Temp::Temp(int _hourlywage, int _hrs, string _name)
	:Employee(_name)
{
	cout << "Temp con with argument" << endl;
	hourlywage = _hourlywage; hrs = _hrs;
}
Temp::Temp(const Temp& t)
	: Employee(t)
{
	cout << "Temp Copy con" << endl;
	hourlywage = t.hourlywage; hrs = t.hrs;
}
Temp::~Temp() {
	cout << "Temp decon" << endl;
}
int Temp::gethourlyWage() {
	return hourlywage;
}
void Temp::sethourlyWage(int _hourlywage) {
	hourlywage = _hourlywage;
}
int Temp::gethrs() {
	return hrs;
}
void Temp::sethrs(int _hrs) {
	hrs = _hrs;
}
int Temp::getPay() {
	return hourlywage * hrs;
}