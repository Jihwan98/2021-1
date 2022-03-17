#include <iostream>
#include "HotDogStand.h"
using namespace std;

int HotDogStand::total_all = 0;

HotDogStand::HotDogStand() {
	id = 999;
	total_stand = 0;
}
HotDogStand::HotDogStand(int id_) {
	id = id_;
	total_stand = 0;
}
HotDogStand::HotDogStand(const HotDogStand& obj) {
	id = obj.id;
	total_stand = obj.total_stand;
}
HotDogStand::~HotDogStand() {

}
void HotDogStand::JustSold() {
	total_stand++;
	total_all++;
}
int HotDogStand::getTotal_stand() {
	return total_stand;
}

int HotDogStand::getTotal_all() {
	return total_all;
}