#include <iostream>
using namespace std;

int* func(int size);

int main() {
	// 사용자가 원하는 갯수를 얻은 후에
	// 그 수만큼의 dynamic array를 확보한다
	// 사용자로부터 그 갯수만큼의 정수를 입력받는다.
	// 평균을 계산해서 출력한다.
	// memory를 해지한다.
	int size;
	cout << "몇 개의 정수를 입력하시겠습니까? : ";
	cin >> size;
	//int* ip = new int[size];
	// func() 에서 확보한 dynamic memory를 main에서 사용하고 해지하자.
	int* ip = func(size);
	cout << "갯수만큼 정수를 입력하시오 : ";
	for (int i = 0; i < size; i++) {
		cin >> *(ip + i);
	}
	int sum = 0;
	
	for (int i = 0; i < size; i++) {
		sum += *(ip + i);
	}
	float average = (float)sum / (float)size;
	cout << "합 = " << sum << ", 평균 = " << average << endl;
	cout << "delete 전 ip = " << ip << endl;
	cout << "delete 전 *ip = " << *ip << endl;

	delete[] ip; ip = NULL;

	cout << "delete 후 ip = " << ip << endl;
	cout << "delete 후 *ip = " << *ip << endl;

	return 0;
}


int* func(int size) {
	int* ret = new int[size];
	return ret;
}