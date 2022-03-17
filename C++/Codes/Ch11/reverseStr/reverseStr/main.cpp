#include <iostream>
using namespace std;

char* reverseStrDM(char* src, int len);
char* reverseStrArr(char* src, int len);

int main() {
	char orig[] = "ABCD";
	int len = strlen(orig);
	//char* copy = reverseStrDM(orig, len);
	char* copy = reverseStrArr(orig, len);
	cout << "copy : " << copy << endl; // 2. Memory use
	delete[] copy; copy = NULL; // 3. Free the memory

	return 0;
}
char* reverseStrArr(char* src, int len) {
	char rev[10];
	for (int i = 0; i < len; i++) {
		rev[i] = src[len - i - 1];
	}
	rev[len] = NULL; // NULL 대신 '\0'도 가능
	return rev;
}

char* reverseStrDM(char* src, int len) {
	char* rev = new char[len + 1]; // 1. Dyanamic Memory Allocation on Heap -> persistent 성질
	for (int i = 0; i < len; i++) {
		rev[i] = src[len - i - 1];
	}
	rev[len] = NULL; // NULL 대신 '\0'도 가능
	return rev;
}