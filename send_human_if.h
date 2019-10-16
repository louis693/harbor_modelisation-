#ifndef SEND_HUMAN_IF_H
#define SEND_HUMAN_IF_H

#include "systemc.h"//????
#include "send_human_if.h"
class send_human_if:public sc_interface
{
    public: virtual void send_human()=0;
};
#endif // SEND_HUMAN_IF_H
