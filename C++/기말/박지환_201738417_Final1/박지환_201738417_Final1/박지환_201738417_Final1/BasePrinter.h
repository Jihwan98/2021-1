#ifndef BASEPRINTER_H
#define BASEPRINTER_H
#include <string>
using namespace std;
class BasePrinter {
protected:
	string model_name;
	string model_maker;
	int paper;
public:
	BasePrinter();
	BasePrinter(const string& _name, const string& _maker, int _paper);
	BasePrinter(const BasePrinter& p);
	virtual ~BasePrinter();
	string getModel_name();
	void setModel_name(const string& _name);
	string getModel_maker();
	void setModel_maker(const string& _maker);
	int getPaper();
	void setPaper(int _paper);
	virtual void Print(int pages) = 0;
	virtual void Show() = 0;
};
#endif