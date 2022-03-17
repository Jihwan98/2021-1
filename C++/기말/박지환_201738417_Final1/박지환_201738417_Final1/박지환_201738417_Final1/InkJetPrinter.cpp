#include <iostream>
#include "InkJetPrinter.h"
using namespace std;

InkJetPrinter::InkJetPrinter() 
	:BasePrinter()
{
	ink = 0;
}
InkJetPrinter::InkJetPrinter(const string& _name, const string& _maker, int _paper, int _ink)
	: BasePrinter(_name, _maker, _paper)
{
	ink = _ink;
}
InkJetPrinter::InkJetPrinter(const InkJetPrinter& i) 
	: BasePrinter(i)
{
	ink = i.ink;
}
InkJetPrinter::~InkJetPrinter() {

}
int InkJetPrinter::getInk() {
	return ink;
}
void InkJetPrinter::setInk(int _ink) {
	ink = _ink;
}
void InkJetPrinter::Print(int pages) {
	if (paper < pages) {
		cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
	}
	else if (ink < pages) {
		cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
	}
	else
	{
		paper = paper - pages;
		ink = ink - pages;
		cout << "프린트하였습니다." << endl;
	}
}
void InkJetPrinter::Show() {
	cout << model_name << " ," << model_maker << " ,남은 종이 " << paper << "장 ,남은 잉크 " << ink << endl;
}