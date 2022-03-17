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
	Geometric(const string& color, bool filled);
	~Geometric();
	string getColor() const;
	void setColor(const string& color);
	bool isFilled() const;
	void setFilled(bool filled);
	string toString() const;
};
#endif