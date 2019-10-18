#include "systemc.h"
#include <iostream>
#include <random>

using namespace std;

class fish_ship_to_radio_base_if : public sc_interface {
public:
    virtual void get_coming_message(const string message) ;
};

class fish_ship_to_staff_if : public sc_interface {
public:
    virtual void get_fish(const int fish) = 0;
};

class radio_base_to_staff_if : public sc_interface {
public:
    virtual void get_working_message(const string message) ;
};

class staff_to_fish_ship_if : public sc_interface {
public:
    virtual void get_unload_message(const string message) ;
};

class staff_to_truck_if : public sc_interface {
public:
    virtual void get_fish_to_truck() = 0;
};

class truck_to_staff_if : public sc_interface {
public:
    virtual void get_full_capacity_message(const string message);
};

class truck_to_warehouse_if : public sc_interface {
public:
    virtual void get_fish_to_warehouse() = 0;
};

class fish_ship : public sc_module, public staff_to_fish_ship_if {


public:
    sc_port<fish_ship_to_radio_base_if> tx_message_to_radio_base_port;
    sc_port<fish_ship_to_staff_if> tx_fish_to_staff_port;
    SC_CTOR(fish_ship) {
        cout << "fish ship was created!" << endl;

        SC_THREAD(fish_generator);
    }
    void get_unload_message() {

    }

    void send_coming_message(){}

    void fish_generator() {

    }
};

class radio_base : public sc_module, public fish_ship_to_radio_base_if {


public:


    sc_port<radio_base_to_staff_if> tx_message_to_staff_port;
    SC_CTOR(radio_base) {
        cout << "Radio base was created!" << endl;

    }
    void get_coming_message() {

    }

     void send_working_message(){}


};

class staff : public sc_module, public radio_base_to_staff_if, public fish_ship_to_staff_if, public truck_to_staff_if {


public:

    sc_port<staff_to_fish_ship_if> tx_message_to_fish_ship_port;
    sc_port<staff_to_truck_if> tx_fish_to_truck_port;

    SC_CTOR(staff) {
        cout << "Staff was created!" << endl;


    }
    void get_working_message() {

    }
    void get_fish(){}

    void get_full_capacity_message(){}

    void send_unloading_message(){}

    void send_fish_to_truck(){}

};

class truck : public sc_module, public staff_to_truck_if {
public:
    sc_port<truck_to_staff_if> tx_message_to_staff_port;
    sc_port<truck_to_warehouse_if> tx_fish_to_warehouse_port;
    SC_CTOR(truck) { cout << "Truck was created!" << endl; }

    void get_fish_to_truck(){}

    void send_full_capacity_message(){}


    void send_fish_to_warehouse(){}
};

class warehouse : public sc_module, public truck_to_warehouse_if {
public:

    SC_CTOR(warehouse) {
        cout << "Warehouse was created!" << endl; }

 void get_fish_to_warehouse(){}
};

class harbor: public sc_module {
public:
    fish_ship m_fish_ship;
    radio_base m_radio_base;
    staff m_staff;
    truck m_truck;
    warehouse m_warehouse;

    SC_CTOR(harbor) : m_fish_ship("fish_ship"), m_radio_base("radio_base"), m_staff("staff"), m_truck("truck"), m_warehouse("warehouse") {
        cout << "Harbor was created!" << endl;
        // fish_ship binding

        m_fish_ship.tx_message_to_radio_base_port(m_radio_base);
        m_fish_ship.tx_fish_to_staff_port(m_staff);


        // radio_base binding
        m_radio_base.tx_message_to_staff_port(m_staff);

        // staff binding
        m_staff.tx_message_to_fish_ship_port(m_fish_ship);
        m_staff.tx_fish_to_truck_port(m_truck);

        // truck binding
        m_truck.tx_message_to_staff_port(m_staff);
        m_truck.tx_fish_to_warehouse_port(m_warehouse);

};

int sc_main(int argc, char *argv[]) {
    harbor Petersburg("Main_Harbor");
    sc_start(200, SC_NS);
    return 0;
}
