#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;
void FuncP(Person p) {
	cout << "I'm in FuncP()" << endl;
	p.ShowData();
}
void FuncS(Student s) {
	cout << "I'm in FuncS()" << endl;
	s.ShowData();
}
int main() {
	Person p1(21, "�忹��");
	p1.ShowData();
	Person p2(p1);
	p2.ShowData();
	FuncP(p2);
	//FuncS(p2);error C2664: 'void FuncS(Student)': �μ� 1��(��) 'Person'���� 'Student'(��)�� ��ȯ�� �� �����ϴ�.
	Student s1(25, "�̿���", 201835777, "ComputerEngineering");
	s1.ShowData();
	Student s2(s1);
	s2.ShowData();
	FuncS(s2);
	FuncP(s2);
	s2.Person::ShowData();
	return 0;
}