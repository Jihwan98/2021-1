#include <iostream>
#include "HotDogStand.h"
using namespace std;

int main() {
	cout << "�� ���� stand �� ����ðڽ��ϱ�? : ";
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
			cout << "0 ���� " << n-1 << " ������ ������ �Է����ּ���." << endl;
			continue;
		}
	}


	return 0;
}