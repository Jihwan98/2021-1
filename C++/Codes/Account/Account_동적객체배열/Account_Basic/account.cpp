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
	int len = strlen(_name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, _name);
	name[len] = '\0';
}
Account::Account(const Account& acc) {
	cout << "deep copy constructor" << endl;
	id = acc.id;
	balance = acc.balance;
	int len = strlen(acc.name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, acc.name);
	name[len] = '\0';
}
Account::~Account() {
	cout << "deconstructor" << endl;
	delete[] name; name = NULL;
}
Account& Account::operator=(const Account& acc) {
	cout << "deep assignment operator overloading" << endl;
	if (this != &acc) { // self assignment check
		id = acc.id;
		balance = acc.balance;
		delete[] name; name = NULL;
		int len = strlen(acc.name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, acc.name);
		name[len] = '\0';
	}
	return *this;
}

void Account::ShowAllData() {
	cout << "���� id: " << id;
	cout << "\tbalance: " << balance;
	cout << "\tname: " << name << endl;
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
void Account::setId(int _id) {
	id = _id;
}
void Account::setBalance(int _balance) {
	balance = _balance;
}
void Account::setName(const char* _name) {
	if (name) {
		delete[] name; name = NULL;
	}
	int len = strlen(_name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, _name);
	name[len] = '\0';
}