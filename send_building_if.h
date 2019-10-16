#ifndef SEND_BUILDING_IF_H
#define SEND_BUILDING_IF_H

#include "systemc.h"//????
#include "send_building_if.h"
class send_building_if:public sc_interface
{
    virtual void send_building(const int data)=0;
};

#endif // SEND_BUILDING_IF_H
