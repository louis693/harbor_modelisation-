#ifndef TRANSPORT_H
#define TRANSPORT_H
//#include "systemc.h" //????
#include "send_human_if.h"
#include "send_building_if.h"
#include "send_product_if.h"
class transport: public sc_module, public send_human_if, public send_building_if, public send_product_if{
public:
    SC_CTOR(transport);
    void send_human();
    void send_product();
    void send_building(const int data);
};

#endif // TRANSPORT_H
