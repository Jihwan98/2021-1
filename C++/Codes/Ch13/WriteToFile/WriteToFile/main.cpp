#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ofstream output("scores.txt"); // relative path
	if (!output) {
		cout << "File open Error" << endl;
		return 0;
	}
	//output << "John" << " " << 'T' << " " << "Smith" << " " << 90 << endl;
	//output << "Erik" << " " << 'K' << " " << "Jones" << " " << 80 << endl;
	//output << "Mike" << " " << 'M' << " " << "Dilworth" << " " << 99 << endl;
	string fn, ln;
	char m;
	int score;
	// Ask user firts name, last name, middle initial and score.
	// until user input quit for first name
	while (true) {
		cout << "FirstName[quit to stop] : "; cin >> fn;
		if (fn == "quit"||fn == "Quit") {
			break;
		}
		cout << "MiddleInitial : "; cin >> m;
		cout << "LastName : "; cin >> ln;
		cout << "Score : "; cin >> score;
		output << fn << " " << m << " " << ln << " " << score << endl;
		cout << "----------------------" << endl;
	}
	
	output.close();
	cout << "Done" << endl;
	return 0;
}