#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius; // client ���� access �Ұ� 
public:
	Circle();
	Circle(double r);
	double getArea();
	double getRadius();
	void setRadius(double r);
};

#endif