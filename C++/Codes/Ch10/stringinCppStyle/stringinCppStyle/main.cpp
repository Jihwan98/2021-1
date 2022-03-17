#include <iostream>
#include <string>
using namespace std;

int main() {
	string S[3] = { "Alpha go", "Steven Jobs", "Foo Bar" };
	string* p = S;
	cout << "address of S[0] : " << &S[0] << endl;
	cout << "address of S[1] : " << &S[1] << endl;
	cout << "address of S[2] : " << &S[2] << endl;
	cout << "sizeof(S[1]) : " << sizeof(S[1]) << endl; // 28 bytes
	
	for (int i = 0; i < 3; i++) {
		// index expression with array name
		cout << S[i] << " ";
		// pointer expression with array name
		cout << *(S + i) << " ";
		// pointer expression with pointer variable, p
		cout << *(p + i) << endl;
	}

	//char cstyle[] = "Are you a string, too?";
	//string cppstyle = "Who am I?";
	//cout << "cstyle = " << cstyle << endl;
	//cout << "cppstyle = " << cppstyle << endl;
	//// 문자열 크기와 변수의 크기
	//cout << "sizeof(string) = " << sizeof(string) << endl;
	//cout << "strlen(cstyle) = " << strlen(cstyle) << endl;
	//cout << "sizeof(cstyle) = " << sizeof(cstyle) << endl;
	//cout << "sizeof(cppstyle) = " << sizeof(cppstyle) << endl;
	//cout << "cppstyle.size() = " << cppstyle.size() << endl;
	//// 문자열 복사
	//char A[50] = "Sedol Lee"; // 9
	//char B[50] = "Alpha Go"; // 8
	//strcpy_s(B, sizeof(B), A);
	//cout << "B : " << B << endl;
	//string Astr = "Sedol Lee";
	//string Bstr = "Alpha Go";
	//Bstr = Astr;
	//cout << "Bstr : " << Bstr << endl;
	//cout << "Bstr.size() = " << Bstr.size() << endl;
	//// string input without space
	//cout << "C style string input (no space): ";
	//cin >> A;
	//cout << "C++ style string input (no space): ";
	//cin >> Astr;
	//cout << "A: " << A << endl << "Astr : " << Astr << endl;
	//cin.clear();
	//cin.ignore();
	//// string input with space
	//cout << "C style string input (with space): ";
	//cin.getline(A, sizeof(A));
	//cout << "C++ style string input (with space): ";
	//getline(cin, Astr);
	//cout << "A: " << A << endl << "Astr : " << Astr << endl;


	return 0;
}