#ifndef DA_H
#define DA_H
const int ARR_SIZE = 4;
class DA {
public:
	int size;
	int* ptr;
	DA();
	DA(int size);
	DA(const DA& d);
	DA& operator=(const DA& d);
	~DA();
	void ShowYourSelf();
};
#endif