#include "people.h"

void staff::get_fish(){
    fish_in_hand = rx_fish_from_ship_port->get_product();
}


void staff::put_product(sc_int<8> product){
    fish_in_hand=product;
}
sc_int<8> staff::get_product(){
    return fish_in_hand;
}
