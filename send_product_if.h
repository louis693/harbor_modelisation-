#ifndef SEND_PRODUCT_IF_H
#define SEND_PRODUCT_IF_H

#include "systemc.h"//????
#include "send_product_if.h"
class send_product_if:public sc_interface
{
    virtual void send_product(const int data)=0;
};

#endif // SEND_PRODUCT_IF_H
