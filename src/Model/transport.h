#ifndef TRANSPORT_H
#define TRANSPORT_H
#include "systemc.h"
#include "interfaces.h"


class truck : public sc_module, public staff_hands, public radio_channel {
public:
    sc_port<radio_channel> tx_message_to_staff_port;
    sc_port<staff_hands> tx_fish_to_warehouse_port;

    SC_HAS_PROCESS(truck);

    truck (sc_module_name name) : sc_module (name) {
        SC_THREAD (get_fish_to_truck);
        cout << "Track was created!" << endl;
       // sensitive<<warehouse;
    }


    void get_fish_to_truck();

    void send_full_capacity_message();

    void send_fish_to_warehouse();
};


#endif // TRANSPORT_H
