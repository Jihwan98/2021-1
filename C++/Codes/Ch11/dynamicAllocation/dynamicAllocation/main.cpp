#include <iostream>
using namespace std;

int* func(int size);

int main() {
	// ����ڰ� ���ϴ� ������ ���� �Ŀ�
	// �� ����ŭ�� dynamic array�� Ȯ���Ѵ�
	// ����ڷκ��� �� ������ŭ�� ������ �Է¹޴´�.
	// ����� ����ؼ� ����Ѵ�.
	// memory�� �����Ѵ�.
	int size;
	cout << "�� ���� ������ �Է��Ͻðڽ��ϱ�? : ";
	cin >> size;
	//int* ip = new int[size];
	// func() ���� Ȯ���� dynamic memory�� main���� ����ϰ� ��������.
	int* ip = func(size);
	cout << "������ŭ ������ �Է��Ͻÿ� : ";
	for (int i = 0; i < size; i++) {
		cin >> *(ip + i);
	}
	int sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += *(ip + i);
	}
	float average = (float)sum / (float)size;
	cout << "�� = " << sum << ", ��� = " << average << endl;
	cout << "delete �� ip = " << ip << endl;
	cout << "delete �� *ip = " << *ip << endl;

	delete[] ip; ip = NULL;

	cout << "delete �� ip = " << ip << endl;
	cout << "delete �� *ip = " << *ip << endl;

	return 0;
}


int* func(int size) {
	int* ret = new int[size];
	return ret;
}