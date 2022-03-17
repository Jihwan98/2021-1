#include <iostream>
#include "DA.h"
using namespace std;

DA::DA() {
	cout << "without arg constructor" << endl;
	size = ARR_SIZE;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		*(ptr + i) = 0;
	}
}
DA::DA(int size) {
	cout << "with arg constructor" << endl;
	this->size = size;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		*(ptr + i) = 0;
	}
}
DA::DA(const DA& d) {
	cout << "deep copy constructor" << endl;
	size = d.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		*(ptr + i) = d.ptr[i];
	}
}
DA& DA::operator=(const DA& d) {
	cout << "deep assignment operator overloading" << endl;
	if (this != &d) {
		// release memory
		delete[] ptr;
		// allocate memory
		ptr = new int[d.size];
		// copy
		for (int i = 0; i < size; i++) {
			*(ptr + i) = d.ptr[i]; // d.(*(ptr+i))
		}
	}
	return *this;
}
DA::~DA() {
	cout << "deconstructor" << endl;
	if (ptr) {
		delete[] ptr;
		ptr = NULL;
	}
}
// heap에 저장돼 있는 요소의 값을 출력한다.
void DA::ShowYourself() {
	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << endl;
	}
}