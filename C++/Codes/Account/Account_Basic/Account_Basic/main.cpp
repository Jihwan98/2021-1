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
		cout << "1. 계좌 생성" << endl;
		cout << "2. 계좌 정보 보기" << endl;
		cout << "3. 입금" << endl;
		cout << "4. 출금" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "Choose: " << endl;
		char input;
		cin >> input;
		int input_num = input - '0';
		if (input_num == 1) { //1. 계좌 생성
			if (count < num) {
				cout << "생성 계좌의 정보를 입력해주세요. 계좌id, 잔액, 이름: ";
				int _id, _balance;
				char _name[100];
				cin >> _id >> _balance >> _name;
				accounts[count].setId(_id);
				accounts[count].setBalance(_balance);
				accounts[count].setName(_name);
				cout << "계좌가 생성되었습니다." << endl;
				accounts[count].ShowAllData();
				count += 1;
			}
			else {
				cout << "생성 가능 계좌 개수를 초과합니다." << endl;
				cout << "생성 가능 최대 개수 : " << num << endl;
			}
		}
		else if (input_num == 2) { //2. 계좌 정보 보기
			for (int i = 0; i < num; i++) {
				cout << "-----------------" << endl;
				cout << i << "번째 계좌 정보" << endl;
				accounts[i].ShowAllData();
			}
		}
		else if (input_num == 3) { //3. 입금
			cout << "입금할 계좌의 id를 입력해주세요: ";
			int input_id;
			cin >> input_id;
			for (int i = 0; i < num; i++) {
				if (accounts[i].getId() == input_id) {
					cout << "입금할 금액을 입력해주세요: ";
					int input_val;
					cin >> input_val;
					cout << "입금 후 잔액: " << accounts[i].InMoney(input_val) << endl;
					break;
				}
			}
		}
		else if (input_num == 4) { //4. 출금
			cout << "출금할 계좌의 id를 입력해주세요: ";
			int input_id;
			cin >> input_id;
			for (int i = 0; i < num; i++) {
				if (accounts[i].getId() == input_id) {
					cout << "출금할 금액을 입력해주세요: ";
					int input_val;
					cin >> input_val;
					if (accounts[i].OutMoney(input_val)) {
						cout << "출금 하였습니다. 출금 후 잔액: " << accounts[i].getBalance() << endl;
					}
					else {
						cout << "잔액이 부족합니다." << endl;
						break;
					}
					break;
				}
			}
		}
		else if (input_num == 5) {
			cout << "프로그램이 종료됩니다" << endl;
			break;
		}
		else {
			cout << "1~5를 입력해주세요" << endl;
		}
	}
	

	return 0;
}

// OOP를 구성하는 중요한 4가지 개념
// abstraction, encapsulation, inheritance, polymorphism