#include <iostream>
#include "point.h"
using namespace std;
const int MAX = 3;

int main() {
	int x, y;
	cout << "1. 정적 객체 배열 방식" << endl;
	Point A[MAX];
	for (int i = 0; i < MAX; i++) {
		cout << i << "번째 포인트 입력_정적 객체 배열 방식 (x y): ";
		cin >> x >> y;
		(A + i)->setX(x); (A + i)->setY(y); //A[i].setX(x); A[i].setY(y);
	}
	cout << "결과 출력" << endl;
	for (int i = 0; i < MAX; i++) {
		(A + i)->Print(); //A[i].Print();
	}
	cout << "2. 동적 객체 배열 방식" << endl;
	int n = MAX; // 또는 사용자에게 물어서 n의 값을 변경.
	Point* B = new Point[n];
	for (int i = 0; i < n; i++) {
		cout << i << "번째 포인트 입력_동적 객체 배열 방식 (x y): ";
		cin >> x >> y;
		(B + i)->setX(x); (B + i)->setY(y); //B[i].setX(x); B[i].setY(y);
	}
	cout << "결과 출력" << endl;
	for (int i = 0; i < n; i++) {
		(B + i)->Print(); //B[i].Print();
	}
	cout << "3. 정적 객체포인터 배열 방식" << endl;
	Point* P[MAX]; // stack에 Point* 배열이 생성. 요소의 데이터 타입은 Point*.
	// 사용자에게 x, y를 입력받는다. Heap에 Point 객체 하나를 생성한다.
	// 이때, 인자 있는 생성자를 활용한다.
	for (int i = 0; i < MAX; i++) {
		cout << i << "번째 포인트 입력_정적 객체포인터 배열 방식 (x y): ";
		cin >> x >> y;
		P[i] = new Point(x, y);
	}
	cout << "결과 출력" << endl;
	for (int i = 0; i < MAX; i++) {
		P[i]->Print();
	}
	cout << "4. 메모리 clean up" << endl;
	delete[] B; B = NULL;
	for (int i = 0; i < MAX; i++) {
		if (P[i]) {
			delete P[i]; P[i] = NULL;
		}
	}
	return 0;
}