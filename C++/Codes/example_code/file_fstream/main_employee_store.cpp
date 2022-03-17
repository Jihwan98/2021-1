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
	//Employee e("오수진");//Employee: 추상 클래스라 생성불가.
	Employee* E[MAX];//객체 포인터배열
	int count = 0;
	int choice;
	while (true) {
		printMenu();
		cout << "메뉴를 선택하세요: ";
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
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}
	return 0;
}
void printMenu() {
	cout << "----------------MENU--------------" << endl;
	cout << "1. 직원 입력 [Permanent]" << endl;
	cout << "2. 직원 입력 [Temporary]" << endl;
	cout << "3. 직원 입력 [SalesPerson]" << endl;
	cout << "4. 모든 직원 급여 보기 [Show Monthly Wage]" << endl;
	cout << "5. 모든 직원 급여 저장하기 [Store Monthly Wage]" << endl;
	cout << "6. 종료 [Exit]" << endl;
}
//사용자에게 파일명을 묻는다.
//쓰는 방식은 이름 스페이스 월급 endl
//append 방식
void insertPerm(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "최대" << MAX << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	else {
		int salary;
		string name;
		cout << "이름: "; cin >> name;
		cout << "월급: "; cin >> salary;
		E[count] = new Permanent(salary, name);
		count++;
	}
}
void insertTemp(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "최대" << MAX << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	else {
		int hourlyWage;
		int hrs;
		string name;
		cout << "이름: "; cin >> name;
		cout << "시급: "; cin >> hourlyWage;
		cout << "시간: "; cin >> hrs;
		E[count] = new Temporary(hourlyWage, hrs, name);
		count++;
	}
}
void insertSales(Employee** E, int& count, int MAX) {
	if (count >= MAX) {
		cout << "최대" << MAX << "명의 직원 정보를 저장할 수 있습니다." << endl;
		return;
	}
	else {
		int basicsalary;
		int earning;
		string name;
		cout << "이름: "; cin >> name;
		cout << "기본급: "; cin >> basicsalary;
		cout << "판매액: "; cin >> earning;
		E[count] = new SalesPerson(basicsalary, earning, name);//Base pointer로의 Upcasting
		count++;
	}
}
void showAll(Employee** E, int count) {
	for (int i = 0;i < count;i++) {
		cout << "이름: " << E[i]->getName() << " ";
		cout << "월급: " << E[i]->getPay() << endl;
	}
}
void storeWage(Employee** E, int count) {
	string name;
	cout << "저장할 파일 이름: "; cin >> name;
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