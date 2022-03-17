#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius; // client ���� access �Ұ� 
public:
	Circle();
	Circle(double r);
	~Circle(); // �Ҹ��� (�������� �ݴ�) clean up
	double getArea();
	double getRadius();
	void setRadius(double r);
};

#endif