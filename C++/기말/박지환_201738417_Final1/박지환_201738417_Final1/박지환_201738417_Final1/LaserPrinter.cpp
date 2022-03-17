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
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (toner < pages) {
		cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else
	{
		paper = paper - pages;
		toner = toner - pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
}
void LaserPrinter::Show() {
	cout << model_name << " ," << model_maker << " ,���� ���� " << paper << "�� ,���� ��� " << toner << endl;
}