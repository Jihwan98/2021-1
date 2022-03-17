#include <iostream>
#include "BBB.h"
using namespace std;

BBB::BBB() {
	cout << "BBB 인자 없는 생성자" << endl;
	d = 0; name[0] = NULL;
}
BBB::BBB(int _d, const char* _name) {
	cout << "BBB 인자 있는 생성자" << endl;
	d = _d;
	strcpy_s(name, strlen(_name) + 1, _name);
}
BBB::~BBB() {
	cout << "BBB 소멸자" << endl;
}
void BBB::Print() {
	cout << "d name: " << d << " " << name << endl;
	// cout << "pri: " << pri << endl; error C2248: 'AAA::pri': private 멤버('AAA' 클래스에서 선언)에 액세스할 수 없습니다.
	cout << "pro pub: " << pro << " " << pub << endl;
}