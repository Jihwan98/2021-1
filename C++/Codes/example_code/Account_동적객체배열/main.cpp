#include <iostream>
#include "account.h"
using namespace std;

void PrintMenu();
void MakeAccount(Account* A, int& index, int size);
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
			//Deposit();
			break;
		case WITHDRAW:
			cout << "출금 선택" << endl;
			//Withdraw();
			break;
		case INQUIRE:
			cout << "전체조회 선택" << endl;
			//Inquire();
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
	cout << "---------------MENU-----------------" << endl;
	cout << "1(계좌개설) " << endl;
	cout << "2(입금)" << endl;
	cout << "3(출금)" << endl;
	cout << "4(전체조회)" << endl;
	cout << "5(프로그램 종료)" << endl;
}
void MakeAccount(Account* A, int& index, int size) {
	int id, bal;
	char name[NAME_LEN];
	cout << "계좌개설을 위한 입력(계좌id 잔액 이름): ";
	cin >> id >> bal >> name;
	A[index].setId(id);
	(A + index)->setBalance(bal); // 가장 좋은 방식 most preferred way of coding
	(*(A + index)).setName(name);
	index++;
}