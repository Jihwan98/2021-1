#include <iostream>
#include "point.h"
using namespace std;
const int MAX = 3;

int main() {
	int x, y;
	cout << "1. ���� ��ü �迭 ���" << endl;
	Point A[MAX];
	for (int i = 0; i < MAX; i++) {
		cout << i << "��° ����Ʈ �Է�_���� ��ü �迭 ��� (x y): ";
		cin >> x >> y;
		(A + i)->setX(x); (A + i)->setY(y); //A[i].setX(x); A[i].setY(y);
	}
	cout << "��� ���" << endl;
	for (int i = 0; i < MAX; i++) {
		(A + i)->Print(); //A[i].Print();
	}
	cout << "2. ���� ��ü �迭 ���" << endl;
	int n = MAX; // �Ǵ� ����ڿ��� ��� n�� ���� ����.
	Point* B = new Point[n];
	for (int i = 0; i < n; i++) {
		cout << i << "��° ����Ʈ �Է�_���� ��ü �迭 ��� (x y): ";
		cin >> x >> y;
		(B + i)->setX(x); (B + i)->setY(y); //B[i].setX(x); B[i].setY(y);
	}
	cout << "��� ���" << endl;
	for (int i = 0; i < n; i++) {
		(B + i)->Print(); //B[i].Print();
	}
	cout << "3. ���� ��ü������ �迭 ���" << endl;
	Point* P[MAX]; // stack�� Point* �迭�� ����. ����� ������ Ÿ���� Point*.
	// ����ڿ��� x, y�� �Է¹޴´�. Heap�� Point ��ü �ϳ��� �����Ѵ�.
	// �̶�, ���� �ִ� �����ڸ� Ȱ���Ѵ�.
	for (int i = 0; i < MAX; i++) {
		cout << i << "��° ����Ʈ �Է�_���� ��ü������ �迭 ��� (x y): ";
		cin >> x >> y;
		P[i] = new Point(x, y);
	}
	cout << "��� ���" << endl;
	for (int i = 0; i < MAX; i++) {
		P[i]->Print();
	}
	cout << "4. �޸� clean up" << endl;
	delete[] B; B = NULL;
	for (int i = 0; i < MAX; i++) {
		if (P[i]) {
			delete P[i]; P[i] = NULL;
		}
	}
	return 0;
}