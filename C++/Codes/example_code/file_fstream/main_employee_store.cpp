#include "Employee.h"
#include "Permanent.h"
#include "SalesPerson.h"
#include "Temporary.h"
#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 100;
enum{PERMANENT=1, TEMPORARY, SALESPERSON, SHOW,STORE,EXIT};
void printMenu();
void insertPerm(Employee** E, int& count, int MAX);
void insertTemp(Employee** E, int& count, int MAX);
void insertSales(Employee** E, int& count, int MAX);
void showAll(Employee** E, int count);
void cleanUp(Employee** E, int count);
void storeWage(Employee** E, int count);


int main() {
	//Employee e("������");//Employee: �߻� Ŭ������ �����Ұ�.
	Employee* E[MAX];//��ü �����͹迭
	int count = 0;
	int choice;
	while (true) {
		printMenu();
		cout << "�޴��� �����ϼ���: ";
		cin >> choice;

		switch (choice) {
		case PERMANENT:
			insertPerm(E, count, MAX);
			break;
		case TEMPORARY:
			insertTemp(E, count, MAX);
			break;
		case SALESPERSON:
			insertSales(E, count, MAX);
			break;
		case SHOW:
			showAll(E, count);
			break;
		case STORE:
			storeWage(E, count);
			break;
		case EXIT:
			cleanUp(E, count);
			return 0;
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
	return 0;
}
void printMenu() {
	cout << "----------------MENU--------------" << endl;
	cout << "1. ���� �Է� [Permanent]" << endl;
	cout << "2. ���� �Է� [Temporary]" << endl;
	cout << "3. ���� �Է� [SalesPerson]" << endl;
	cout << "4. ��� ���� �޿� ���� [Show Monthly Wage]" << endl;
	cout << "5. ��� ���� �޿� �����ϱ� [Store Monthly Wage]" << endl;
	cout << "6. ���� [Exit]" << endl;
}
//����ڿ��� ���ϸ��� ���´�.
//���� ����� �̸� �����̽� ���� endl
//append ���
void insertPerm(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "�ִ�" << MAX << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	else {
		int salary;
		string name;
		cout << "�̸�: "; cin >> name;
		cout << "����: "; cin >> salary;
		E[count] = new Permanent(salary, name);
		count++;
	}
}
void insertTemp(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "�ִ�" << MAX << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	else {
		int hourlyWage;
		int hrs;
		string name;
		cout << "�̸�: "; cin >> name;
		cout << "�ñ�: "; cin >> hourlyWage;
		cout << "�ð�: "; cin >> hrs;
		E[count] = new Temporary(hourlyWage, hrs, name);
		count++;
	}
}
void insertSales(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "�ִ�" << MAX << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	else {
		int basicsalary;
		int earning;
		string name;
		cout << "�̸�: "; cin >> name;
		cout << "�⺻��: "; cin >> basicsalary;
		cout << "�Ǹž�: "; cin >> earning;
		E[count] = new SalesPerson(basicsalary, earning, name);//Base pointer���� Upcasting
		count++;
	}
}
void showAll(Employee** E, int count) {
	for (int i = 0;i < count;i++) {
		cout << "�̸�: " << E[i]->getName() << " ";
		cout << "����: " << E[i]->getPay() << endl;
	}
}
void storeWage(Employee** E, int count) {
	string name;
	cout << "������ ���� �̸�: "; cin >> name;
	fstream fout;
	fout.open(name, ios::out | ios::app);
	if (!fout) {
		cout << "File open error" << endl;
		return;
	}
	for (int i = 0;i < count;i++) {
		fout << E[i]->getName() << " " << E[i]->getPay() << endl;
	}
	fout.close();
	cout << "Done" << endl;
}
void cleanUp(Employee** E, int count) {
	for (int i = 0;i < count;i++) {
		delete E[i]; E[i] = NULL;
	}
}