#ifndef LASERPRINTER_H
#define LASERPRINTER_H
#include "BasePrinter.h"
class LaserPrinter : public BasePrinter {
protected:
	int toner;
public:
	LaserPrinter();
	LaserPrinter(const string& _name, const string& _maker, int _paper, int _toner);
	LaserPrinter(const LaserPrinter& L);
	~LaserPrinter();
	int getToner();
	void setToner(int _toner);
	void Print(int pages);
	void Show();
};
#endif