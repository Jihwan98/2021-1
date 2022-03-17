#include <iostream>
#include <fstream>
#include <string>
#include "stacktemplate.h"
using namespace std;

int main() {
	string name;
	cout << "File 이름 : "; cin >> name;
	fstream fout;
	fout.open(name, ios::out);
	if (!fout) {
		cout << "File open error" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore();
	while (true) {
		char text[200];
		cout << "한 줄의 텍스트 입력: ";
		cin.getline(text, sizeof(text));

		cout << "입력된 텍스트를 디스플레이와 화일에 거꾸로 출력하기" << endl;
		
		int n;
		StackTemplate<char> s1(200);
		StackTemplate<char> s2(200);
		for (int i = 0; i < strlen(text); i++) {
			s1.Push(text[i]);
			s2.Push(text[i]);
		}
		n = s1.getTopIdx();
		for (int i = 0; i <= n; i++) {
			cout << s1.Pop();
			fout << s2.Pop();
		}
		fout << endl;
		cout << endl;
		cin.clear();
		char input;
		cout << "계속여부?(Y/N): ";
		cin >> input;
		if (input == 'n' || input == 'N') {
			fout.close();
			return 0;
		}
		cin.clear();
		cin.ignore();
	}

	return 0;
}