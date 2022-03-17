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
		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else if (ink < pages) {
		cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
	}
	else
	{
		paper = paper - pages;
		ink = ink - pages;
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
}
void InkJetPrinter::Show() {
	cout << model_name << " ," << model_maker << " ,���� ���� " << paper << "�� ,���� ��ũ " << ink << endl;
}