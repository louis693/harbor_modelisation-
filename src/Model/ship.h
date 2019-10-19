#ifndef SHIP_H
#define SHIP_H
#include "systemc.h"
#include "interfaces.h"


class fish_ship : public sc_module, public staff_hands {
public:
//    sc_port<radio_channel> tx_message_to_radio_base_port;
    sc_port<staff_hands> tx_fish_to_staff_port;

    sc_int<8> fish;

    SC_HAS_PROCESS(fish_ship);
    fish_ship(sc_module_name name) : sc_module(name){
        SC_METHOD (fish_generator);
        cout << "[fish ship was created!"<< endl;
    }


    void put_product(sc_int<8> product);
    sc_int<8> get_product();

    void get_unload_message();
    void send_coming_message();
    void fish_generator();
};


#endif // SHIP_H
