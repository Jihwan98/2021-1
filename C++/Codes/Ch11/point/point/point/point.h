#ifndef POINT_H
#define POINT_H
class Point {
private:
	int x, y;
public:
	Point();
	Point(int _x, int _y);
	Point(const Point& p);
	~Point();
	void setX(int _x);
	void setY(int _y);
	int getX() const;
	int getY() const;
	void Print() const;
};

#endif