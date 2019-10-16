#ifndef SHIP_H
#define SHIP_H

#include "systemc.h" //????
#include "send_human_if.h"
class ship: public sc_module, public send_human_if{
public:
    SC_CTOR(ship);
    void send_human();
};

#endif // SHIP_H
