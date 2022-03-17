#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius; // client 에서 access 불가 
public:
	Circle();
	Circle(double r);
	double getArea();
	double getRadius();
	void setRadius(double r);
};

#endif