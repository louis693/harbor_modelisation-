#include "people.h"

void staff::get_fish(){
	while (true) {
		wait(nw_e);
		fish_in_hand = get_product();
		std::cout << "Staff get fish, weight = " << fish_in_hand.wight << " [" << sc_time_stamp() << std::endl;
	}
}


void staff::put_product(fish product){
    fish_in_hand = product;
	nw_e.notify();
}
fish staff::get_product(){
    return fish_in_hand;
}
