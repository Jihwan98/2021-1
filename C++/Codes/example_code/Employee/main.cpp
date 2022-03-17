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
	//Employee e("장예정"); 'Employee': 추상 클래스를 인스턴스화할 수 없습니다.
	Employee* E[MAX]; // 객체 포인터 배열
	int count = 0; // 실제 입력된 직원의 수
	int choice;
	while (true) {
		printMenu();
		cout << " 메뉴를 선택하세요: ";
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
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}
}
void printMenu() {
	cout << "-----------MENU-----------" << endl;
	cout << " 1. 직원 입력 [Permanent]" << endl;
	cout << " 2. 직원 입력 [Temporary]" << endl;
	cout << " 3. 직원 입력 [SalesPerson]" << endl;
	cout << " 4. 모든 직원 급여 보기 [Show Monthly Wage]" << endl;
	cout << " 5. 종료[Exit]" << endl;
	cout << "--------------------------" << endl;
}
void insertPerm(Employee** E, int& count, int size) {
	if (count >= size) {
		cout << "최대 " << size << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	int salary;
	string name;
	cout << "이름: "; cin >> name;
	cout << "월급: "; cin >> salary;
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
	cout << "이름: "; cin >> name;
	cout << "시급: "; cin >> hourlyWage;
	cout << "일한 시간: "; cin >> hrs;
	E[count] = new Temp(hourlyWage, hrs, name);
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
	cout << "이름: "; cin >> name;
	cout << "기본급: "; cin >> basicsalary;
	cout << "판매액: "; cin >> earning;
	E[count] = new Sales(basicsalary, earning, name); // Base pointer로의 Upcasting
	count++;
}
void showAll(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		cout << "이름: " << E[i]->getName() << " ";
		cout << "월급: " << E[i]->getPay() << endl;
	}
}
void cleanUp(Employee** E, int count) {
	for (int i = 0; i < count; i++) {
		delete E[i]; E[i] = NULL;
	}
}