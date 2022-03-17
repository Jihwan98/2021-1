#ifndef HD_H
#define HD_H
//hotdogs.cpp
//This program defines a class for tracking hot dog sales.
//
//It tracks the stand's ID number, hot dogs sold at each stand,
//  and hot dogs sold at all stands.

class HotDogStand
{
public:
	HotDogStand();
	HotDogStand(int newID, int newNnumSold);
	int GetID();
	void SetID(int newID);
	void JustSold();
	int GetNumSold();
private:
	int numSold;
	int ID;

public:
	static int GetTotalSold();
private:
	static int totalSold;
};
#endif

