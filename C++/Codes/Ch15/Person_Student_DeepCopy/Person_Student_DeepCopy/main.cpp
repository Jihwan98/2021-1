#include <iostream>
#include "person.h"
#include "student.h"
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
	Person p1(21, "����ȯ");
	p1.ShowData();
	Person p2(p1);
	p2.ShowData();
	FuncP(p2);
	//FuncS(p2); //�� ��ȯ �Ұ�
	Student s1(24, "Ȳ����", 201738442, "�ǿ��ü���а�");
	s1.ShowData();
	Student s2(s1);
	s2.ShowData();
	FuncS(s2);
	FuncP(s2);
	s2.Person::ShowData();

	return 0;
}