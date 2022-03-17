#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	char firstFile[100] = "copy.txt"; // for writing into my relative path
	string secondFile = "c:\\windows\\system.ini"; // for reading from absolute path
	fstream fout;
	fout.open(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << "File open Error" << endl;
		return 0;
	}
	fstream fin;
	fin.open(secondFile, ios::in);
	if (!fin) {
		cout << "File open Error" << endl;
		return 0;
	}
	char c;
	while (true) {
		c = fin.get();
		if (fin.eof()) {
			cout << "End of File" << endl;
			break;
		}
		fout.put(c);
	}
	fin.close();
	fout.close();
	cout << "Done" << endl;
	return 0;
}