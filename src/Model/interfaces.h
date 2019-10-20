#ifndef intefaces_h
#define intefaces_h
#include "systemc.h"
#include "product.h"

class radio_channel : virtual public sc_interface {
public:
    virtual void send_message(fish message) = 0;
    virtual fish recv_message() = 0;
};

class staff_hands : virtual public sc_interface {
public:
    virtual void put_product(fish product) = 0;
    virtual fish get_product() = 0;
};
/*

class fish_ship_to_staff_if : virtual public sc_interface {
public:
    virtual void get_fish(const int fish) = 0;
};

class radio_base_to_staff_if : virtual public sc_interface {
public:
    virtual void get_working_message(const sc_int<8> message) ;
};

class staff_to_fish_ship_if : public sc_interface {
public:
    virtual void get_unload_message(const sc_int<8> message) = 0;
};

class staff_to_truck_if : public sc_interface {
public:
    virtual void get_fish_to_truck() = 0;
};

class truck_to_staff_if : public sc_interface {
public:
    virtual void get_full_capacity_message(const sc_int<8> message);
};

class truck_to_warehouse_if : public sc_interface {
public:
    virtual void get_fish_to_warehouse() = 0;
};
*/

#endif
