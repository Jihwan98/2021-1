#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream input("states.txt");
	if (!input) {
		cout << "File open Error" << endl;
		return 0;
	}
	string city;
	while (true) {
		getline(input, city, '#');
		if (input.eof()) {
			cout << "End of Line" << endl;
			break;
		}
		cout << city << endl;
	}
	input.close();
	cout << "Done" << endl;
	return 0;
}