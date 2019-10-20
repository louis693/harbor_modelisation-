#include "people.h"

void staff::get_fish(){
    fish_in_hand = get_product();
	std::cout << "Staff get fish #" << fish_in_hand;
}


void staff::put_product(sc_int<8> product){
    fish_in_hand=product;
	nw_e.notify();
}
sc_int<8> staff::get_product(){
    return fish_in_hand;
}
