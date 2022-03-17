#include <iostream>
#include "account.h"
using namespace std;

int main() {
	cout << "How many accounts to create?: ";
	int num;
	cin >> num;
	Account* accounts = new Account[num];
	int count = 0;
	while (1) {
		cout << "-----------------" << endl;
		cout << "      MENU       " << endl;
		cout << "-----------------" << endl;
		cout << "1. ���� ����" << endl;
		cout << "2. ���� ���� ����" << endl;
		cout << "3. �Ա�" << endl;
		cout << "4. ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "Choose: " << endl;
		char input;
		cin >> input;
		int input_num = input - '0';
		if (input_num == 1) { //1. ���� ����
			if (count < num) {
				cout << "���� ������ ������ �Է����ּ���. ����id, �ܾ�, �̸�: ";
				int _id, _balance;
				char _name[100];
				cin >> _id >> _balance >> _name;
				accounts[count].setId(_id);
				accounts[count].setBalance(_balance);
				accounts[count].setName(_name);
				cout << "���°� �����Ǿ����ϴ�." << endl;
				accounts[count].ShowAllData();
				count += 1;
			}
			else {
				cout << "���� ���� ���� ������ �ʰ��մϴ�." << endl;
				cout << "���� ���� �ִ� ���� : " << num << endl;
			}
		}
		else if (input_num == 2) { //2. ���� ���� ����
			for (int i = 0; i < num; i++) {
				cout << "-----------------" << endl;
				cout << i << "��° ���� ����" << endl;
				accounts[i].ShowAllData();
			}
		}
		else if (input_num == 3) { //3. �Ա�
			cout << "�Ա��� ������ id�� �Է����ּ���: ";
			int input_id;
			cin >> input_id;
			for (int i = 0; i < num; i++) {
				if (accounts[i].getId() == input_id) {
					cout << "�Ա��� �ݾ��� �Է����ּ���: ";
					int input_val;
					cin >> input_val;
					cout << "�Ա� �� �ܾ�: " << accounts[i].InMoney(input_val) << endl;
					break;
				}
			}
		}
		else if (input_num == 4) { //4. ���
			cout << "����� ������ id�� �Է����ּ���: ";
			int input_id;
			cin >> input_id;
			for (int i = 0; i < num; i++) {
				if (accounts[i].getId() == input_id) {
					cout << "����� �ݾ��� �Է����ּ���: ";
					int input_val;
					cin >> input_val;
					if (accounts[i].OutMoney(input_val)) {
						cout << "��� �Ͽ����ϴ�. ��� �� �ܾ�: " << accounts[i].getBalance() << endl;
					}
					else {
						cout << "�ܾ��� �����մϴ�." << endl;
						break;
					}
					break;
				}
			}
		}
		else if (input_num == 5) {
			cout << "���α׷��� ����˴ϴ�" << endl;
			break;
		}
		else {
			cout << "1~5�� �Է����ּ���" << endl;
		}
	}
	

	return 0;
}

// OOP�� �����ϴ� �߿��� 4���� ����
// abstraction, encapsulation, inheritance, polymorphism