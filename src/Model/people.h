#ifndef PEOPLE_H
#define PEOPLE_H
#include "systemc.h"
#include "interfaces.h"


class staff : public sc_module, public staff_hands {
public:
  //  sc_port <staff_hands> rx_fish_from_ship_port;

    sc_int<8> fish_in_hand;
	sc_event nw_e;

	void get_fish();

  /*  SC_HAS_PROCESS(staff);

    staff (sc_module_name name) : sc_module (name) */ SC_CTOR (staff) {
        SC_THREAD (get_fish);
        cout << "\t[Staff] was created!" << endl;
		dont_initialize();
        sensitive<< nw_e;
    }


    void put_product(sc_int<8> product);
    sc_int<8> get_product();


};

#endif // PEOPLE_H
