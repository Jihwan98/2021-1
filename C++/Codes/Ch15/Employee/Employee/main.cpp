#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
#include "permanent.h"
#include "salesperson.h"
#include "temporary.h"
using namespace std;
const int MAX = 100;
enum { PERMANENT = 1, TEMPORARY, SALESPERSON, SHOW, STORE, EXIT };
void printMenu();
void insertPerm(Employee** E, int& count, int size);
void insertTemp(Employee** E, int& count, int size);
void insertSales(Employee** E, int& count, int size);
void showAll(Employee** E, int count);
void store(Employee** E, int count);
void cleanUp(Employee** E, int count);

int main() {
	Employee* E[MAX]; // 객체 포인터 배열
	int count = 0; // 실제 입력된 직원의 수
	int choice;
	while (true) {
		printMenu();
		cout << "메뉴를 선택하세요 : ";
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
			store(E, count);
			break;
		case EXIT:
			cleanUp(E, count);
			return 0;
		default:
			cout << "잘못된 선택입니다." << endl;
		}
	}
	return 0;
}

void printMenu() {
	cout << "-------------MENU-------------" << endl;
	cout << "1. 직원 입력 [Permanent]" << endl;
	cout << "2. 직원 입력 [Temporary]" << endl;
	cout << "3. 직원 입력 [Salesperson]" << endl;
	cout << "4. 모든 직원 급여 보기 [Show Monthly Wage]" << endl;
	cout << "5. Save All the Employees Salary with name" << endl; // Name Salary
	cout << "6. 종료 [Exit]" << endl;
}
void insertPerm(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "최대 " << size << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	int salary;
	string name;
	cout << "이름 : "; cin >> name;
	cout << "월급 : "; cin >> salary;
	E[count] = new Permanent(salary, name);
	count++;
}
void insertTemp(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "최대 " << size << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	int hourlyWage, hrs;
	string name;
	cout << "이름 : "; cin >> name;
	cout << "시급 : "; cin >> hourlyWage;
	cout << "일한 시간 : "; cin >> hrs;
	E[count] = new Temporary(hourlyWage, hrs, name);
	count++;
}
void insertSales(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "최대 " << size << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	int basicsalary;
	int earning;
	string name;
	cout << "이름 : "; cin >> name;
	cout << "기본급 : "; cin >> basicsalary;
	cout << "판매액 : "; cin >> earning;
	E[count] = new SalesPerson(basicsalary, earning, name); // Base pointer로의 Upcasting
	count++;
}
void showAll(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		cout << "이름 : " << E[i]->getName() << " ";
		cout << "월급 : " << E[i]->getPay() << endl;
	}
}
// In store() function
// Ask user FIle Name, open the file with append mode, Write down name salary
void store(Employee** E, int count) {
	fstream fout;
	string FileName;
	cout << "File Name to store : "; cin >> FileName;
	int append;
	fout.open(FileName, ios::out | ios::app);
	if (!fout) {
		cout << "File open Error" << endl;
		return;
	}
	for (int i = 0; i < count; i++) {
		fout << E[i]->getName() << " " << E[i]->getPay() << endl;
		//string name = E[i]->getName();
		//double pay = E[i]->getPay();
		//fout.put(name);
		//fout.put(' ');
		//fout.put(pay);
	}
	fout.close();
	cout << "Stored in the file" << endl;
}
void cleanUp(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		delete E[i]; E[i] = NULL;
	}
}