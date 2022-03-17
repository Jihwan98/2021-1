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
			cout << "���°��� ����" << endl;
			MakeAccount(A, index, size);
			break;
		case DEPOSIT:
			cout << "�Ա� ����" << endl;
			//Deposit();
			break;
		case WITHDRAW:
			cout << "��� ����" << endl;
			//Withdraw();
			break;
		case INQUIRE:
			cout << "��ü��ȸ ����" << endl;
			//Inquire();
			break;
		case EXIT:
			cout << "���α׷� ���� ����" << endl;
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
	cout << "1(���°���) " << endl;
	cout << "2(�Ա�)" << endl;
	cout << "3(���)" << endl;
	cout << "4(��ü��ȸ)" << endl;
	cout << "5(���α׷� ����)" << endl;
}
void MakeAccount(Account* A, int& index, int size) {
	int id, bal;
	char name[NAME_LEN];
	cout << "���°����� ���� �Է�(����id �ܾ� �̸�): ";
	cin >> id >> bal >> name;
	A[index].setId(id);
	(A + index)->setBalance(bal); // ���� ���� ��� most preferred way of coding
	(*(A + index)).setName(name);
	index++;
}