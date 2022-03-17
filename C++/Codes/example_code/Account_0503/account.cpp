#include <iostream>
#include "account.h"
using namespace std;

Account::Account() {
	cout << "���� ���� ������" << endl;
	id = 0;
	balance = 0;
	name = new char[NAME_LEN];
	name[0] = '\0';
}
Account::Account(int _id, int _balance, const char* _name) {
	cout << "���� �ִ� ������" << endl;
	id = _id;
	balance = _balance;
	// memory�� _name�� ���̺��� 1 ũ�� Ȯ���Ѵ�. strlen() �̿��� ��.
	// _name�� name���� �����Ѵ�. strcpy_s() ����� ��.
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
Account::Account(const Account& a) {
	cout << "���� ���� ������" << endl;
	id = a.id;
	balance = a.balance;
	name = new char[strlen(a.name) + 1];
	strcpy_s(name, strlen(a.name) + 1, a.name);
}
Account::~Account() {
	cout << "�Ҹ���" << endl;
}
Account& Account::operator=(const Account& a) {
	cout << "���� ���� ������ �����ε�" << endl;
	if (this != &a) { // self assignment�� checking ����.
		id = a.id;
		balance = a.balance;
		delete[] name; name = NULL;
		name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
	}
	return *this;
}
void Account::ShowAllData() {
	cout << "���� ID: " << id;
	cout << "   �ܾ�: " << balance;
	cout << "   �̸�: " << name << endl;
}
int Account::InMoney(int val) {
	balance += val;
	return balance;
}
bool Account::OutMoney(int val) {
	if (balance >= val) {
		balance -= val;
		return true;
	}
	else
		return false;
}
int Account::getId() {
	return id;
}
int Account::getBalance() {
	return balance;
}
char* Account::getName() {
	return name;
}
void Account::setId(int val) {
	id = val;
}
void Account::setBalance(int val) {
	balance = val;
}
void Account::setName(const char* _name) {
	if (name) {
		delete[] name; name = NULL;
	}
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}