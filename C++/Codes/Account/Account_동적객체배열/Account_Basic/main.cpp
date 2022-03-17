#include <iostream>
#include "account.h"
using namespace std;
void PrintMenu();
void MakeAccount(Account* A, int& index, int size);
void Deposit(Account* A,int index);
void Withdraw(Account* A, int index);
void Inquire(Account* A, int index);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
int main() {	
	int size;
	cout << "How many accounts to create?: ";
	cin >> size;
	Account* A = new Account[size];
	int index = 0;

	int choice;
	while (true) {
		PrintMenu();
		cout << "Choose: ";
		cin >> choice;
		switch (choice) {
		case MAKE:
			cout << "계좌개설 선택" << endl;
			MakeAccount(A, index, size);
			break;
		case DEPOSIT:
			cout << "입금 선택" << endl;
			Deposit(A, index);
			break;
		case WITHDRAW:
			cout << "출금 선택" << endl;
			Withdraw(A, index);
			break;
		case INQUIRE:
			cout << "전체조회 선택" << endl;
			Inquire(A, index);
			break;
		case EXIT:
			cout << "프로그램 종료 선택" << endl;
			delete[] A; A = NULL;
			return 0;
		default:
			cout << "wrong choice" << endl;
			break;
		}
	}
	return 0;
}

void PrintMenu() {
	cout << "-------------MENU-------------" << endl;
	cout << "1(계좌개설)" << endl;
	cout << "2(입금)" << endl;
	cout << "3(출금)" << endl;
	cout << "4(전체조회)" << endl;
	cout << "5(프로그램 종료)" << endl;
}
void MakeAccount(Account* A, int& index, int size) {
	if (index < size) {
		int id, bal;
		char name[NAME_LEN];
		cout << "계좌개설을 위한 입력(계좌id 잔액 이름): ";
		cin >> id >> bal >> name;
		A[index].setId(id);
		(A + index)->setBalance(bal); // 가장 좋은 방식 most preferred way of coding
		(*(A + index)).setName(name);
		index++;
	}
	else {
		cout << "계좌 개설 개수를 초과합니다." << endl;
		cout << "계좌 개설 최대 개수는 " << size << " 입니다." << endl;
	}
}
void Deposit(Account* A, int index) {
	// 사용자로부터 id와 입금액을 입력받는다.
	// id가 존재하는 id인지 check
	int m, id;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> m;
	bool found = false;
	int bal = 0;
	for (int i = 0; i < index; i++) {
		if ((A + i)->getId() == id) { // 존재하는 아이디
			bal = (A + i)->InMoney(m);
			found = true;
			cout << "현재 잔고: " << bal << endl;
			break;
		}
	}
	if (found == false)
		cout << "존재하지 않는 id 입니다." << endl;
}
void Withdraw(Account* A, int index) {
	int m, id;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> m;
	bool found = false;
	for (int i = 0; i < index; i++) {
		if ((A + i)->getId() == id) { // 존재하는 아이디
			if ((A + i)->OutMoney(m)) { // 충분한 balance
				cout << "현재잔고: " << (A + i)->getBalance() << endl;
			}
			else
				cout << "잔고가 충분하지 않습니다." << endl;
			found = true;
		}
	}
	if (found == false)
		cout << "존재하지 않는 id 입니다." << endl;
}
void Inquire(Account* A, int index) {
	for (int i = 0; i < index; i++) {
		(A + i)->ShowAllData(); // A[i].ShowAllData();
	}
}