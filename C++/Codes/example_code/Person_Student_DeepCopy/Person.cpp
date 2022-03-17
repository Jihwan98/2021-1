#include <iostream>
#include "Person.h"
using namespace std;
Person::Person() {
	age = 0;
	name = new char[MAX];
}
Person::Person(int _age, const char* _name) {
	age = _age;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
Person::Person(const Person& p) {
	age = p.age;
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
}
Person::~Person() {
	delete[] name; name = NULL;
	cout << "Person Decon" << endl;
}
Person& Person::operator=(const Person& p) {
	if (this != &p) { // protect from self-assignment
		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}
	return *this;
}
void Person::SetName(const char* _name) {
	delete[] name; name = NULL;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
char* Person::GetName() {
	return name;
}
void Person::SetAge(int _age) {
	age = _age;
}
int Person::GetAge() {
	return age;
}
void Person::ShowData() {
	cout << "이름: " << name << " 나이: " << age << endl;
}