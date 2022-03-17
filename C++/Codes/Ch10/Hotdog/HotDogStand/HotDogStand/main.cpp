#include <iostream>
#include "HotDogStand.h"
using namespace std;

int main() {
	cout << "몇 개의 stand 를 만드시겠습니까? : ";
	int n;
	cin >> n;
	HotDogStand* pstand = new HotDogStand[n];

	while (true)
	{
		cout << "Stand : ";
		char input;
		cin >> input;
		int input_num = input - '0';
		if (input == 'q' || input == 'Q' || input == 'quit' || input == 'Quit') {
			for (int i = 0; i < n; i++) {
				cout << "stands[" << i << "] : " << pstand[i].getTotal_stand() << endl;
			}
			cout << "Total : " << HotDogStand::getTotal_all() << endl;
			break;
		}
		else if (input_num  < n) {
			pstand[input_num].JustSold();
		}
		else {
			cout << "0 에서 " << n-1 << " 사이의 정수를 입력해주세요." << endl;
			continue;
		}
	}


	return 0;
}