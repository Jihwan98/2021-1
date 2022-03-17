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
	cout << "Base의 f()이 불리워짐" << endl;
}
class Derived : public Base {
public:
	virtual ~Derived();
	virtual void f();
};
Derived::~Derived() {
	cout << "Derived Decon" << endl;
}
void Derived::f() {
	cout << "Derived의 f()이 불리워짐" << endl;
}
int main() {
	//// Derived 객체
	//Derived d1;
	//d1.f(); // Derived의 f()이 불리워짐
	//d1.Base::f(); // Base의 f()이 불리워짐
	//// 객체 간 Upcasting
	//Base b1;
	//b1 = d1;
	//b1.f(); // Base의 f()이 불리워짐, virtual 여부와 상관없음.
	//// Pointer 간 Upcasting
	//Base* bptr1 = &d1;
	//bptr1->f(); // Virtual이 있으면 Derived의 f()이 불리워짐. 없으면 Base의 f()이 불리워짐.

	//Derived d, *pDer;
	//pDer = &d;
	//pDer->f(); // Derived의 f()이 불리워짐
	//Base* pBase;
	//pBase = pDer; // 객체 포인터 간 Upcasting
	//pBase->f(); // 동적 Binding 발생, Derived의 f()이 불리워짐.
	//Base bObj;
	//bObj = d; // 객체 간 Upcasting
	//bObj.f(); // Base의 f()이 불리워짐

	Derived* derPtr = new Derived();
	Base* basePtr = new Derived(); // 객체 간 Upcasting
	delete derPtr;
	delete basePtr;
	return 0;
}