#include <iostream>
using namespace std;

int main() {
	// data[0]�� �ּҴ� 0012FEE0
	// memory padding ���� �� ������ �ּ� �߰��� ������ �������� �޸� �������� �׷���
	// d�� �ּҴ� �����ϱ�? 0012FEC0
	int data[5] = { 1, 2, 3, 4, 5 };
	int a = -200;
	int& ref = a;
	char str[18] = "programming fun";
	double d = 78.32;

	return 0;
}