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
	cout << "Base의 f()이 불리어짐" << endl;
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
	cout << "Derived의 f()이 불리어짐" << endl;
}

int main() {
	//// Derived 객체
	//Derived d1;
	//d1.f(); // Derived의 f()이 불리어짐
	//d1.Base::f(); // Base의 f()이 불리어짐
	//// 객체간 upcasting
	//Base b1;
	//b1 = d1;
	//b1.f(); // Base의 f()이 불리어짐 , virtual 여부와 상관없음
	//// 포인터간 upcasting
	//Base* bptr1 = &d1;
	//bptr1->f(); // virtual이 있으면 derived의 f()이 불리어짐. 없으면 base의 f()이 불리어짐.
	//
	//Derived d, *pDer;
	//pDer = &d;
	//pDer->f(); // Derived의 f()이 불리어짐
	//Base* pBase;
	//pBase = pDer; // 객체 포인터 간 upcasting
	//pBase->f(); // 동적 Binding 발생, Derived의 f()이 불리어짐.
	//Base bObj;
	//bObj = d; // 객체 간 upcasting
	//bObj.f(); // Base의 f()이 불리어짐

	Derived* derPtr = new Derived();
	Base* basePtr = new Derived(); // 객체 간 upcasting
	delete derPtr;
	delete basePtr;

	return 0;
}