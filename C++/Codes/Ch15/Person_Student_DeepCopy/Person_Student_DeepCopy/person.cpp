#include <iostream>
#include "person.h"
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
	cout << "Person decon" << endl;
}
Person& Person::operator=(const Person& p) {
	if (this != &p) { // protecte from self-assignment
		age = p.age;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name);
	}
	return *this;
}
void Person::setAge(int _age) {
	age = _age;
}
int Person::getAge() {
	return age;
}
void Person::setName(const char* _name) {
	delete[] name; name = NULL;
	name = new char[strlen(_name) + 1];
	strcpy_s(name, strlen(_name) + 1, _name);
}
char* Person::getName() {
	return name;
}
void Person::ShowData() {
	cout << "이름: " << name << " 나이 :" << age << endl;
}