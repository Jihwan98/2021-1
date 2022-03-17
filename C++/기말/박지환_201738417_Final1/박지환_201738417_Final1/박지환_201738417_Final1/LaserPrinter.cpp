#include <iostream>
#include "LaserPrinter.h"
using namespace std;

LaserPrinter::LaserPrinter() 
	:BasePrinter()
{
	toner = 0;
}
LaserPrinter::LaserPrinter(const string& _name, const string& _maker, int _paper, int _toner) 
	: BasePrinter(_name, _maker, _paper)
{
	toner = _toner;
}
LaserPrinter::LaserPrinter(const LaserPrinter& L) 
	: BasePrinter(L)
{
	toner = L.toner;
}
LaserPrinter::~LaserPrinter() {

}
int LaserPrinter::getToner() {
	return toner;
}
void LaserPrinter::setToner(int _toner) {
	toner = _toner;
}
void LaserPrinter::Print(int pages) {
	if (paper < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (toner < pages) {
		cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
	}
	else
	{
		paper = paper - pages;
		toner = toner - pages;
		cout << "프린트하였습니다." << endl;
	}
}
void LaserPrinter::Show() {
	cout << model_name << " ," << model_maker << " ,남은 종이 " << paper << "장 ,남은 토너 " << toner << endl;
}