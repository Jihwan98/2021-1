#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"
class Student : public Person {
protected:
	int sid;
	char* major;
public:
	Student();
	Student(int _age, const char* _name, int _sid, const char* _major);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student & s);
	void setSid(int _sid);
	int getSid();
	void setMajor(const char* _major);
	char* getMajor();
	void ShowData();
};

#endif