#ifndef BUILDING_H
#define BUILDING_H
#include "systemc.h"
#include "interfaces.h"

class warehouse : public sc_module, public radio_channel {
public:

    SC_HAS_PROCESS(warehouse);

    warehouse (sc_module_name name) : sc_module (name) {
        SC_THREAD (get_fish_to_warehouse);
        cout << "Ware House was created!" << endl;
       // sensitive<<warehouse;
    }
    void get_fish_to_warehouse();
};


class radio_base : public sc_module, public radio_channel {
public:
    sc_port<radio_channel> tx_message_to_staff_port;
    sc_port<radio_channel> rx_message_to_ship;

    sc_event ship_arrives;

    SC_HAS_PROCESS(radio_base);

    radio_base (sc_module_name name) : sc_module (name) {
        SC_THREAD (get_coming_message);
        cout << "Radio base was created!" << endl;
        sensitive<<ship_arrives;
    }
    void get_coming_message();
    void send_working_message();
};



#endif // BUILDING_H
