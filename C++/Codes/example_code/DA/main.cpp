#include <iostream>
#include "DA.h"
using namespace std;

int main() {
	DA a;
	DA b(5);
	DA c(3);
	b.ShowYourself();
	c = b;
	c.ShowYourself();
	return 0;
}