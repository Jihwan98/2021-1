#include <iostream>
using namespace std;

int funcmin(int ip[], int num);

int main() {
	char C[] = {'D', 'a', 'l', 'l', 'a', 's'};
	char D[] = "Dallas";

	cout << "(void*)C : " << (void*)C << endl;
	cout << "(void*)D : " << (void*)D << endl;
	cout << "C : " << C << endl;
	cout << "sizeof(C) : " << sizeof(C) << endl;
	cout << "strlen(C) : " << strlen(C) << endl;
	cout << "D : " << D << endl;
	cout << "sizeof(D) : " << sizeof(D) << endl;
	cout << "strlen(D) : " << strlen(D) << endl;

	//int A[3] = { 1, 2, 3 };
	//int B[3] = { 10, 20, 30 };
	//// A = B; error A´Â »ó¼ö Æ÷ÀÎÅÍ´Ù.
	//cout << "A = " << A << endl;
	//cout << "address of A[0] = " << &A[0] << endl;
	//cout << "sizeof(int) = " << sizeof(int) << endl;
	//cout << "sizeof(A) = " << sizeof(A) << endl; // int size (4) * ¿ä¼ÒÀÇ °¹¼ö (3) = 12
	//int res = funcmin(A, 3);

	return 0;
}
int funcmin(int ip[], int num) {
	cout << "sizeof(ip) = " << sizeof(ip) << endl;
	return 1;
}


/*
(void*)C : 006FF924
(void*)D : 006FF914
C : DallasÌÌÌÌÌÌ:P+5T?
sizeof(C) : 6
strlen(C) : 19
D : Dallas
sizeof(D) : 7
strlen(D) : 6
*/