#ifndef HOTDOGSTAND_H
#define HOTDOGSTAND_H
class HotDogStand {
private:
	int id;
	int total_stand;
public:
	HotDogStand();
	HotDogStand(int id_);
	HotDogStand(const HotDogStand& obj);
	~HotDogStand();
	void JustSold();
	int getTotal_stand();
private:
	static int total_all;
public:
	static int getTotal_all();
};

#endif