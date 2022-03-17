#include <iostream>
#include "BasePrinter.h"
#include "InkJetPrinter.h"
#include "LaserPrinter.h"
using namespace std;
void cleanUp(BasePrinter** BP);
int main() {
	BasePrinter* BP[5] = { NULL };
	BP[0] = new InkJetPrinter("Officejet V40", "HP", 20, 30);
	BP[1] = new LaserPrinter("SCX-6x45", "SamsungElec", 15, 10);
	BP[2] = new LaserPrinter("SM56", "SamsungElec", 20, 30);
	BP[3] = new LaserPrinter("KM5", "Emerson", 10, 10);
	BP[4] = new InkJetPrinter("Officejet V70", "HP", 30, 30);
	
	while (true) {
		int choice;
		int pages;
		char input;
		cout << "�����ͳѹ�[0:4]: ";
		cin >> choice;
		if (choice > 5 || choice < 0) {
			cout << "0~4 ������ ��ȣ�� �Է����ּ���." << endl << endl;
		}
		else {
			cout << "����Ʈ�� ������ ��: ";
			cin >> pages;
			
			BP[choice]->Print(pages);
			BP[choice]->Show();

			cout << "��� ����Ʈ �Ͻðڽ��ϱ�?[y/n]: ";
			cin >> input;
			if (input == 'n' || input == 'N') {
				cleanUp(BP);
				return 0;
			}
			cout << endl;
		}
	}
	

	return 0;
}

void cleanUp(BasePrinter** BP) {
	for (int i = 0; i < 5; i++) {
		delete BP[i]; BP[i] = NULL;
	}
}