#include "ship.h"
#include <random>

void FishShip::fish_generator(){
	 fishtank = new fish[10];
	
	int i = 0;
	while (i<10){
		tx_fish_to_staff_port->put_product(fishtank[i]);
		i++;
		wait(2, SC_NS);
	}
}


void FishShip::put_product(fish product){
}

fish FishShip ::get_product(){
	fish a;
	return a;
}
