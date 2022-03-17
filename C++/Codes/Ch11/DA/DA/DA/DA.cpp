#include <iostream>
#include "DA.h"
using namespace std;

DA::DA() {
	cout << "인자 없는 생성자" << endl;
	size = ARR_SIZE;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		*(ptr + i) = 0;
	}
}
DA::DA(int size) {
	cout << "인자 있는 생성자" << endl;
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
		size = d.size;
		// release memory
		delete[] ptr; ptr = NULL;
		// allocate memory
		ptr = new int[size];
		// copy
		for (int i = 0; i < size; i++) {
			*(ptr + i) = d.ptr[i]; // d.(*(ptr + i))
		}
	}
	return *this;
}
DA::~DA() {
	cout << "deconstructor" << endl;
	if (ptr) {
		delete[] ptr; ptr = NULL;
	}
}
// heap에 저장되어 있는 요소의 값을 출력
void DA::ShowYourSelf() {
	for (int i = 0; i < size;i++) {
		cout << i << "번째 값 : " << ptr[i] << endl;
	}
}