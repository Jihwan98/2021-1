#include <iostream>
#include "Student.h"
using namespace std;
Student::Student()
	:Person()
{
	sid = 0;
	major = new char[MAX];
}
Student::Student(int _age, const char* _name, int _sid, const char* _major)
	:Person(_age, _name)
{
	sid = _sid;
	major = new char[strlen(_major) + 1];
	strcpy_s(major, strlen(_major) + 1, _major);
}
Student::Student(const Student& s)
	:Person(s)
{
	sid = s.sid;
	major = new char[strlen(s.major) + 1];
	strcpy_s(major, strlen(s.major) + 1, s.major);
}
Student::~Student() {
	cout << "Student Decon" << endl;
	delete[] major; major = NULL;
}
Student& Student::operator=(const Student& s) {
	if (this != &s) {
		Person::operator=(s);
		sid = s.sid;
		major = new char[strlen(s.major) + 1];
		strcpy_s(major, strlen(s.major) + 1, s.major);
	}
	return *this;
}
void Student::SetSid(int _sid) {
	sid = _sid;
}
int Student::GetSid() {
	return sid;
}
void Student::SetMajor(const char* _major) {
	delete[] major; major = NULL;
	major = new char[strlen(_major) + 1];
	strcpy_s(major, strlen(_major) + 1, _major);
}
char* Student::GetMajor() {
	return major;
}
void Student::ShowData() {
	Person::ShowData();
	cout << " student ID: " << sid << " major: " << major << endl;
}