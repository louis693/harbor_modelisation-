#ifndef PEOPLE_H
#define PEOPLE_H
#include "systemc.h"
#include "interfaces.h"


class staff : public sc_module, public staff_hands {
public:
    sc_port <staff_hands> rx_fish_from_ship_port;

    sc_int<8> fish_in_hand;

    SC_HAS_PROCESS(staff);

    staff (sc_module_name name) : sc_module (name) {
        SC_THREAD (get_fish);
        cout << "Staff was created!" << endl;
       // sensitive<<warehouse;
    }


    void put_product(sc_int<8> product);
    sc_int<8> get_product();


    void get_working_message();
    void get_fish();

    void get_full_capacity_message();
    void send_unloading_message();
    void send_fish_to_truck();

};

#endif // PEOPLE_H
