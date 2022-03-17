#include <iostream>
using namespace std;

char* shiftStringBy1char(char* src, int len);

int main() {
	char original[] = "BINGO JJANG!!!";
	int ori_len = strlen(original);
	cout << original << endl;
	char* copy = shiftStringBy1char(original, ori_len);
	for (int i = 0; i < ori_len; i++) {
		cout << copy << endl;
		copy = shiftStringBy1char(copy, ori_len);
	}
	delete[] copy; copy = NULL;
	return 0;
}


char* shiftStringBy1char(char* src, int len) {
	char* shiftString = new char[len + 1];

	for (int i = 0; i < len-1; i++) {
		shiftString[i] = src[i + 1];
	}
	shiftString[len - 1] = src[0];
	shiftString[len ] = NULL;

	return shiftString;
}