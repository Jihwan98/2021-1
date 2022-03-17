#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student :public Person
{
protected:
	int sid;
	char* major;
public:
	Student();
	Student(int _age, const char* _name, int _sid, const char* _major);
	Student(const Student& s);
	~Student();
	Student& operator=(const Student& s);
	void SetSid(int _sid);
	int GetSid();
	void SetMajor(const char* _major);
	char* GetMajor();
	void ShowData();
};
#endif