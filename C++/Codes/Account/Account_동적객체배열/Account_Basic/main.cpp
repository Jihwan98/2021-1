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
			cout << "���°��� ����" << endl;
			MakeAccount(A, index, size);
			break;
		case DEPOSIT:
			cout << "�Ա� ����" << endl;
			Deposit(A, index);
			break;
		case WITHDRAW:
			cout << "��� ����" << endl;
			Withdraw(A, index);
			break;
		case INQUIRE:
			cout << "��ü��ȸ ����" << endl;
			Inquire(A, index);
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
	cout << "-------------MENU-------------" << endl;
	cout << "1(���°���)" << endl;
	cout << "2(�Ա�)" << endl;
	cout << "3(���)" << endl;
	cout << "4(��ü��ȸ)" << endl;
	cout << "5(���α׷� ����)" << endl;
}
void MakeAccount(Account* A, int& index, int size) {
	if (index < size) {
		int id, bal;
		char name[NAME_LEN];
		cout << "���°����� ���� �Է�(����id �ܾ� �̸�): ";
		cin >> id >> bal >> name;
		A[index].setId(id);
		(A + index)->setBalance(bal); // ���� ���� ��� most preferred way of coding
		(*(A + index)).setName(name);
		index++;
	}
	else {
		cout << "���� ���� ������ �ʰ��մϴ�." << endl;
		cout << "���� ���� �ִ� ������ " << size << " �Դϴ�." << endl;
	}
}
void Deposit(Account* A, int index) {
	// ����ڷκ��� id�� �Աݾ��� �Է¹޴´�.
	// id�� �����ϴ� id���� check
	int m, id;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> m;
	bool found = false;
	int bal = 0;
	for (int i = 0; i < index; i++) {
		if ((A + i)->getId() == id) { // �����ϴ� ���̵�
			bal = (A + i)->InMoney(m);
			found = true;
			cout << "���� �ܰ�: " << bal << endl;
			break;
		}
	}
	if (found == false)
		cout << "�������� �ʴ� id �Դϴ�." << endl;
}
void Withdraw(Account* A, int index) {
	int m, id;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> m;
	bool found = false;
	for (int i = 0; i < index; i++) {
		if ((A + i)->getId() == id) { // �����ϴ� ���̵�
			if ((A + i)->OutMoney(m)) { // ����� balance
				cout << "�����ܰ�: " << (A + i)->getBalance() << endl;
			}
			else
				cout << "�ܰ� ������� �ʽ��ϴ�." << endl;
			found = true;
		}
	}
	if (found == false)
		cout << "�������� �ʴ� id �Դϴ�." << endl;
}
void Inquire(Account* A, int index) {
	for (int i = 0; i < index; i++) {
		(A + i)->ShowAllData(); // A[i].ShowAllData();
	}
}