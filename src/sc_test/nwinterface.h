#include "systemc.h"

#ifndef H_NWINTERFACE
#define H_NWINTERFACE
class nwinterface0 : virtual public sc_interface {
public:
	virtual void write_ch0(sc_int<8> data) = 0;
	virtual sc_int<8> read_ch0() = 0;
};

class nwinterface1 :  virtual public sc_interface {
public:
	virtual void write_ch1(sc_int<8> data ) = 0;
	virtual sc_int<8> read_ch1() = 0;
};

class nwinterface2 : virtual public sc_interface {
public:
	virtual void write_ch2(sc_int<8> data) = 0;
	virtual sc_int<8> read_ch2() = 0;
};
#endif