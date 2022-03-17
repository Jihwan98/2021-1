#ifndef RECT_H
#define	RECT_H
#include "geometric.h"
class Rect :public Geometric {
private:
	double width;
	double height;
public:
	Rect();
	Rect(double _width, double _height);
	Rect(double _width, double _height, const string& _color, bool _filled);
	Rect(const Rect& r);
	~Rect();
	double getWidth();
	void setWidth(double _width);
	double getHeight();
	void setHeight(double _height);
	double getArea();
	double getPerimeter();
	string toString();
};

#endif // !RECT_H
