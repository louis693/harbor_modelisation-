#include "ship.h"
#include <random>

void fish_ship::fish_generator(){
    fish=rand()%250;
    tx_fish_to_staff_port->put_product(fish);
}




void fish_ship::put_product(sc_int<8> product){
    fish=product;
}
sc_int<8> fish_ship::get_product(){
    return fish;
}
