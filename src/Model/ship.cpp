#include "ship.h"
#include <random>

void FishShip::fish_generator(){
    fish=rand()%250;
    tx_fish_to_staff_port->put_product(fish);
}


void FishShip::put_product(sc_int<8> product){
    fish=product;
	nw_e.notify();
}

sc_int<8> FishShip
::get_product(){
    return fish;
}
