#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <iostream>
using namespace std;

class CharStack {
private:
	int topIdx;
	char* stackPtr;
public:
	CharStack(int size);
	~CharStack();
	void Push(const char& pushVal);
	char Pop();
	int getTopIdx();
};
CharStack::CharStack(int size) {
	stackPtr = new char[size];
	topIdx = -1;
}
CharStack::~CharStack() {
	delete[] stackPtr; stackPtr = NULL;
}
void CharStack::Push(const char& pushVal) {
	topIdx++;
	stackPtr[topIdx] = pushVal;
}
char CharStack::Pop() {
	return stackPtr[topIdx--];
}
int CharStack::getTopIdx() {
	return topIdx;
}


#endif 