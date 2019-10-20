#include "systemc.h"
#include "nwinterface.h"

#ifndef H_CHECKBYTEUNIT
#define H_CHECKBYTEUNIT


class  CheckByteUnit : public sc_module, public nwinterface1 {
public:
	sc_port <nwinterface1> cb_out;
	sc_int<8> data1, pkg, count = 0;
	sc_event nw_e1;


	SC_HAS_PROCESS(CheckByteUnit);
	CheckByteUnit(sc_module_name name) : sc_module(name) {
		SC_THREAD(check);
		cout << "[Check byte unit] | <" << sc_time_stamp() << "> | Online" << endl;
		dont_initialize();
		sensitive << nw_e1;
	}

	void check();
	void write_ch1(sc_int<8> data);
	sc_int<8> read_ch1();
};
#endif