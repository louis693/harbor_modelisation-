#ifndef PRODUCT_H
#define PRODUCT_H
#include "systemc.h"
#include <random>
#include <cstdlib>
	


class fish {
public:
	sc_int<8> wight;
	fish::fish() { 
		std::srand(11);
		wight = rand() % 200;
		wight++;
	}
	fish val() {return *this;}
};

#endif // SHIP_H
