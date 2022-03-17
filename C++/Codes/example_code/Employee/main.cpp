#include <iostream>
#include <fstream>
#include "Employee.h"
#include "SalesPerson.h"
#include "Permanent.h"
#include "Temporary.h"
using namespace std;
const int MAX = 100;
enum { PERMANENT = 1, TEMPORARY, SALESPERSON, SHOW, EXIT };

void printMenu();
void insertPerm(Employee** E, int& count, int size);
void insertTemp(Employee** E, int& count, int size);
void insertSales(Employee** E, int& count, int size);
void showAll(Employee** E, int count);
void cleanUp(Employee** E, int count);

int main() {
	//Employee e("�忹��"); 'Employee': �߻� Ŭ������ �ν��Ͻ�ȭ�� �� �����ϴ�.
	Employee* E[MAX]; // ��ü ������ �迭
	int count = 0; // ���� �Էµ� ������ ��
	int choice;
	while (true) {
		printMenu();
		cout << " �޴��� �����ϼ���: ";
		cin >> choice;

		switch (choice)
		{
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
		case EXIT:
			cleanUp(E, count);
			return 0;
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
	}
}
void printMenu() {
	cout << "-----------MENU-----------" << endl;
	cout << " 1. ���� �Է� [Permanent]" << endl;
	cout << " 2. ���� �Է� [Temporary]" << endl;
	cout << " 3. ���� �Է� [SalesPerson]" << endl;
	cout << " 4. ��� ���� �޿� ���� [Show Monthly Wage]" << endl;
	cout << " 5. ����[Exit]" << endl;
	cout << "--------------------------" << endl;
}
void insertPerm(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "�ִ� " << size << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	int salary;
	string name;
	cout << "�̸�: "; cin >> name;
	cout << "����: "; cin >> salary;
	E[count] = new Permanent(salary, name);
	count++;
}
void insertTemp(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "�ִ� " << size << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	int hourlyWage, hrs;
	string name;
	cout << "�̸�: "; cin >> name;
	cout << "�ñ�: "; cin >> hourlyWage;
	cout << "���� �ð�: "; cin >> hrs;
	E[count] = new Temp(hourlyWage, hrs, name);
	count++;
}
void insertSales(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "�ִ� " << size << "���� ���� ������ ������ �� �ֽ��ϴ�." << endl;
		return;
	}
	int basicsalary;
	int earning;
	string name;
	cout << "�̸�: "; cin >> name;
	cout << "�⺻��: "; cin >> basicsalary;
	cout << "�Ǹž�: "; cin >> earning;
	E[count] = new Sales(basicsalary, earning, name); // Base pointer���� Upcasting
	count++;
}
void showAll(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		cout << "�̸�: " << E[i]->getName() << " ";
		cout << "����: " << E[i]->getPay() << endl;
	}
}
void cleanUp(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		delete E[i]; E[i] = NULL;
	}
}