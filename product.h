#ifndef PRODUCT_H
#define PRODUCT_H

#include "systemc.h"//????
#include "send_human_if.h"
class product: public sc_module, public send_human_if{
public:
    SC_CTOR(product);
    void send_human();
};

#endif // SHIP_H
