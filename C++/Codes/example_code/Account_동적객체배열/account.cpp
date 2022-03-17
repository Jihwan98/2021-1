#include <iostream>
#include "account.h"
using namespace std;

Account::Account() {
	cout << "인자 없는 생성자" << endl;
	id = 0;
	balance = 0;
	name = new char[NAME_LEN];
	name[0] = '\0';
}
Account::Account(int _id, int _balance, const char* _name) {
	cout << "인자 있는 생성자" << endl;
	id = _id;
	balance = _balance;
	// memory를 _name의 길이보다 1 크게 확보한다. strlen() 이용할 것.
	// _name을 name으로 복사한다. strcpy_s() 사용할 것.
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
Account::Account(const Account& a) {
	cout << "깊은 복사 생성자" << endl;
	id = a.id;
	balance = a.balance;
	name = new char[strlen(a.name) + 1];
	strcpy_s(name, strlen(a.name) + 1, a.name);
}
Account::~Account() {
	cout << "소멸자" << endl;
}
Account& Account::operator=(const Account& a) {
	cout << "깊은 대입 연산자 오버로딩" << endl;
	if (this != &a) { // self assignment를 checking 하자.
		id = a.id;
		balance = a.balance;
		delete[] name; name = NULL;
		name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
	}
	return *this;
}
void Account::ShowAllData() {
	cout << "계좌 ID: " << id;
	cout << "   잔액: " << balance;
	cout << "   이름: " << name << endl;
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