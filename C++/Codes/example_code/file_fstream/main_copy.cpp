#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	char firstFile[100] = "copy.txt"; // relative path
	string secondFile = "c:\\Windows\\system.ini"; // absolute path
	fstream fout; // for writing
	fout.open(firstFile, ios::out | ios::app); // default = overwrite
	if (!fout) {
		cout << "File open error" << endl;
		return 0;
	}
	fstream fin;
	fin.open(secondFile, ios::in);
	if (!fin) {
		cout << "File open error" << endl;
		return 0;
	}
	char c;
	while (true) {
		c = fin.get();
		if (fin.eof()) {
			break;
		}
		fout.put(c);
	}
	fin.close();
	fout.close();
	cout << "Done" << endl;
	return 0;
}