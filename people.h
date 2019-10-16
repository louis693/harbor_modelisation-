#ifndef PEOPLE_H
#define PEOPLE_H

#include "systemc.h"//????
#include "send_human_if.h"
class people:public sc_module{
    sc_port<send_human_if> hum_to_ship;
    sc_port<send_human_if> hum_to_transport;
    sc_port<send_human_if> hum_to_building;
    SC_CTOR(people);
    void human_generator();
};
#endif // PEOPLE_H
