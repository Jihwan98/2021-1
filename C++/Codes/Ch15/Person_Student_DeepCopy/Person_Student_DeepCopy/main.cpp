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
	Person p1(21, "박지환");
	p1.ShowData();
	Person p2(p1);
	p2.ShowData();
	FuncP(p2);
	//FuncS(p2); //형 변환 불가
	Student s1(24, "황혜지", 201738442, "의용생체공학과");
	s1.ShowData();
	Student s2(s1);
	s2.ShowData();
	FuncS(s2);
	FuncP(s2);
	s2.Person::ShowData();

	return 0;
}