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
	void SetX(int _x);
	void SetY(int _y);
	int GetX() const;
	int GetY() const;
	void Print() const;
};
#endif
