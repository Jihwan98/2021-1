#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ofstream output("scores.txt"); // for write
	if (!output) {
		cout << "File open error." << endl;
		return 0;
	}
	/*output << "John" << " " << 'T' << " " << "Smith" << " " << 90 << endl;
	output << "Eric" << " " << 'K' << " " << "Jones" << " " << 80 << endl;
	output << "Mike" << " " << 'M' << " " << "Dilworth" << " " << 100 << endl;*/
	string fn, ln;
	char m;
	int score;
	while (true) {
		// ��� �Է¹޴ٰ� First Name: �� quit�� �Է��ϸ� break;
		cout << "First Name[quit to stop]: "; cin >> fn;
		if (fn == "quit" || fn == "Quit") {
			break;
		}
		cout << "Middle Initial: "; cin >> m;
		cout << "Last Name: "; cin >> ln;
		cout << "Score: "; cin >> score;
		output << fn << " " << m << " " << ln << " " << score << endl;
		cout << "---------------------------------" << endl;
	}
	output.close();
	cout << "Done" << endl;
	return 0;
}