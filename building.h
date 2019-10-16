#ifndef BUILDING_H
#define BUILDING_H

#include "systemc.h"//????
#include "send_human_if.h"
class building: public sc_module, public send_human_if{
public:
    SC_CTOR(building);
    void send_human();
};
#endif // BUILDING_H
