#include <iostream>
#include "count.h"
using namespace std;
// void increment(Count c, int t);
void incrementByRef(Count& c, int& t);
int main() {
	Count obj;
	int times = 0;
	for (int i = 0; i < 100; i++) {
		// increment(obj, times);
		incrementByRef(obj, times);
	}
	cout << "obj.getCt(): " << obj.getCt() << endl;
	cout << "times: " << times << endl;

	return 0;
}
void increment(Count c, int t) {
	// c.ct++;
	int ct = c.getCt();
	c.setCt(ct + 1);
	t++;
}
void incrementByRef(Count& c, int& t) { // Count& c = obj;
	int ct = c.getCt();
	c.setCt(ct + 1);
	t++;
}