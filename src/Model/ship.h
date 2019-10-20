#ifndef SHIP_H
#define SHIP_H
#include "systemc.h"
#include "product.h"
#include "interfaces.h"
#include <iostream>


class FishShip : public sc_module, public staff_hands {
public:
    sc_port<staff_hands> tx_fish_to_staff_port;
	sc_in_clk schedule;
    fish *fishtank;
	sc_event nw_e;

    SC_HAS_PROCESS(FishShip);
    FishShip(sc_module_name name) : sc_module(name){
        SC_THREAD (fish_generator);
		std::cout << "\t[Fish Ship] was created!"<< std::endl;
        dont_initialize();
		sensitive << schedule.pos();
    }


    void put_product(fish product);
	fish get_product();

    void fish_generator();
	
};


#endif // SHIP_H
