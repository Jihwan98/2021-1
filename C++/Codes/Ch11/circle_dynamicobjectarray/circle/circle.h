#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius; // client ���� access �Ұ� 
public:
	Circle();
	Circle(double radius);
	~Circle(); // �Ҹ��� (�������� �ݴ�) clean up
	double getArea();
	double getRadius();
	void setRadius(double r);
	void showYourself();
};

#endif