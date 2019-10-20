#ifndef PEOPLE_H
#define PEOPLE_H
#include "systemc.h"
#include "product.h"
#include "interfaces.h"


class staff : public sc_module, public staff_hands {
public:
  //  sc_port <staff_hands> rx_fish_from_ship_port;

	fish fish_in_hand;
	sc_event nw_e;

	void get_fish();

    SC_HAS_PROCESS(staff);

    staff (sc_module_name name) : sc_module (name){
        SC_THREAD(get_fish);
        cout << "\t[Staff] was created!" << endl;
		dont_initialize();
        sensitive<< nw_e;
    }


    void put_product(fish product);
	fish get_product();


};

#endif // PEOPLE_H
