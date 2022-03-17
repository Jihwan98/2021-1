#include "HD.h"
int HotDogStand::totalSold = 0;


// ======================
// HotDogStand::HotDogStand
// The default constructor initializes the ID and num sold to zero.
// ======================
HotDogStand::HotDogStand()
{
	numSold = 0;
	ID = 0;
}

// ======================
// HotDogStand::HotDogStand
// This constructor initializes the ID and num sold.
// ======================
HotDogStand::HotDogStand(int newID, int newNumSold)
{
	numSold = newNumSold;
	ID = newID;
}

// ======================
// HotDogStand::GetID
// Returns the ID number of this stand.
// ======================
int HotDogStand::GetID()
{
	return ID;
}

// ======================
// HotDogStand::SetID
// Sets the ID number of this stand.
// ======================
void HotDogStand::SetID(int newID)
{
	ID = newID;
}

// ======================
// HotDogStand::JustSold
// Increments the number of hotdogs this stand
// has sold by one.
// ======================
void HotDogStand::JustSold()
{
	numSold++;	// increment number sold at this stand
	totalSold++;    // increment number sold across all stands
}

// ======================
// HotDogStand::GetNumSold
// Returns the number of hotdogs this stand has sold.
// ======================
int HotDogStand::GetNumSold()
{
	return numSold;
}

// ======================
// HotDogStand::GeTotalSold
// Returns the number of hotdogs sold by all stands
// ======================
int HotDogStand::GetTotalSold()
{
	return totalSold;
}


