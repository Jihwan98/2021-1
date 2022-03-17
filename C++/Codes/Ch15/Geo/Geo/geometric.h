#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <string>
using namespace std;

class Geometric {
private:
	string color;
	bool filled;
public:
	Geometric();
	Geometric(const string& _color, bool _filled);
	Geometric(const Geometric& g);
	~Geometric();
	void setColor(const string& _color);
	string getColor();
	void setFilled(bool _filled);
	bool isFilled();
	string toString();
};

#endif 