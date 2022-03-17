#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius; // client 에서 access 불가 
public:
	Circle();
	Circle(double radius);
	~Circle(); // 소멸자 (생성자의 반대) clean up
	double getArea();
	double getRadius();
	void setRadius(double r);
	void showYourself();
};

#endif