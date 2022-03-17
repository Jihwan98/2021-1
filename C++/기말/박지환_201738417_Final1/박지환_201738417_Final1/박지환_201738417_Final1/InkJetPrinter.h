#ifndef INKJETPRINTER_H
#define INKJETPRINTER_H
#include "BasePrinter.h"
class InkJetPrinter : public BasePrinter{
protected:
	int ink; 
public:
	InkJetPrinter();
	InkJetPrinter(const string& _name, const string& _maker, int _paper, int _ink);
	InkJetPrinter(const InkJetPrinter& i);
	~InkJetPrinter();
	int getInk();
	void setInk(int _ink);
	void Print(int pages);
	void Show();
};
#endif