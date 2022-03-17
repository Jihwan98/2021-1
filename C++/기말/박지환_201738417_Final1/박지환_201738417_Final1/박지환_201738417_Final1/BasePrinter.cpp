#include <iostream>
#include "BasePrinter.h"
using namespace std;

BasePrinter::BasePrinter() {
	model_name = "noname";
	model_maker = "noname";
	paper = 0;
}
BasePrinter::BasePrinter(const string& _name, const string& _maker, int _paper) {
	model_name = _name;
	model_maker = _maker;
	paper = _paper;
}
BasePrinter::BasePrinter(const BasePrinter& p) {
	model_name = p.model_name;
	model_maker = p.model_maker;
	paper = p.paper;
}
BasePrinter::~BasePrinter() {
	
}
string BasePrinter::getModel_name() {
	return model_name;
}
void BasePrinter::setModel_name(const string& _name) {
	model_name = _name;
}
string BasePrinter::getModel_maker() {
	return model_maker;
}
void BasePrinter::setModel_maker(const string& _maker) {
	model_maker = _maker;
}
int BasePrinter::getPaper() {
	return paper;
}
void BasePrinter::setPaper(int _paper) {
	paper = _paper;
}
//void BasePrinter::Print(int pages) {
//	if (paper < pages) {
//		cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
//	}
//	else
//	{
//		paper = paper - pages;
//		cout << "����Ʈ�Ͽ����ϴ�." << endl;
//	}
//}
//void BasePrinter::Show() {
//	cout << "---------------------------------------" << endl;
//	cout << "������ �𵨸� : " << model_name << endl;
//	cout << "������ ������ : " << model_maker << endl;
//	cout << "�μ������ܷ� : " << paper << endl;
//	cout << "---------------------------------------" << endl;
//}