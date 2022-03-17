#include <iostream>
using namespace std;
class Base {
public:
	virtual ~Base();
	virtual void f();
};
Base::~Base() {
	cout << "Base Decon" << endl;
}

void Base::f() {
	cout << "Base�� f()�� �Ҹ�����" << endl;
}

class Derived :public Base {
public:
	virtual ~Derived();
	virtual void f();
};
Derived::~Derived() {
	cout << "Derived Decon" << endl;
}
void Derived::f() {
	cout << "Derived�� f()�� �Ҹ�����" << endl;
}

int main() {
	//// Derived ��ü
	//Derived d1;
	//d1.f(); // Derived�� f()�� �Ҹ�����
	//d1.Base::f(); // Base�� f()�� �Ҹ�����
	//// ��ü�� upcasting
	//Base b1;
	//b1 = d1;
	//b1.f(); // Base�� f()�� �Ҹ����� , virtual ���ο� �������
	//// �����Ͱ� upcasting
	//Base* bptr1 = &d1;
	//bptr1->f(); // virtual�� ������ derived�� f()�� �Ҹ�����. ������ base�� f()�� �Ҹ�����.
	//
	//Derived d, *pDer;
	//pDer = &d;
	//pDer->f(); // Derived�� f()�� �Ҹ�����
	//Base* pBase;
	//pBase = pDer; // ��ü ������ �� upcasting
	//pBase->f(); // ���� Binding �߻�, Derived�� f()�� �Ҹ�����.
	//Base bObj;
	//bObj = d; // ��ü �� upcasting
	//bObj.f(); // Base�� f()�� �Ҹ�����

	Derived* derPtr = new Derived();
	Base* basePtr = new Derived(); // ��ü �� upcasting
	delete derPtr;
	delete basePtr;

	return 0;
}