#include <iostream>
using namespace std;

int main() {
	// data[0]의 주소는 0012FEE0
	// memory padding 없이 맨 왼쪽의 주소 중간의 변수명 오른쪽의 메모리 컨텐츠를 그려라
	// d의 주소는 무엇일까? 0012FEC0
	int data[5] = { 1, 2, 3, 4, 5 };
	int a = -200;
	int& ref = a;
	char str[18] = "programming fun";
	double d = 78.32;

	return 0;
}