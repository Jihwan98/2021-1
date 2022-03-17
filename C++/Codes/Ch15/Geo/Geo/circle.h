#ifndef CIRCLE_H
#define CIRCLE_H
#include "geometric.h"

class Circle: public Geometric {
private:
	double radius; // client 에서 access 불가 
public:
	Circle();
	Circle(double r);
	Circle(double r, const string& _color, bool _filled);
	Circle(const Circle& c);
	~Circle();
	double getArea();
	double getRadius();
	void setRadius(double r);
	double getPerimeter();
	double getDiameter();
	string toString();
};

#endif