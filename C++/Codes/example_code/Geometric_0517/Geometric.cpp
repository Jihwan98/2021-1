#include <iostream>
#include "Geometric.h"
using namespace std;
Geometric::Geometric()
{
	cout << "Geo Constructor without arg" << endl;
	color = "white";
	filled = false;
}
Geometric::Geometric(const string& color, bool filled)
{
	cout << "Geo Constructor with arg" << endl;
	this->color = color;
	this->filled = filled;
}
Geometric::Geometric(const Geometric& g) {
	cout << "Geo Copy constructor " << endl;
	color = g.color;
	filled = g.filled;
}
Geometric::~Geometric() {
	cout << "Geo Deconstructor " << endl;
}
string Geometric::getColor() const
{
	return color;
}
void Geometric::setColor(const string& color)
{
	this->color = color;
}
bool Geometric::isFilled() const
{
	return filled;
}
void Geometric::setFilled(bool filled)
{
	this->filled = filled;
}
string Geometric::toString() const
{
	return "나는 Geometric 객체입니다.";
}