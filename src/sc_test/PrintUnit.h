
#include "systemc.h"
#include "nwinterface.h"

#ifndef H_PRINTUNIT
#define H_PRINTUNIT

class  PrintUnit :public sc_module, public nwinterface1 {
public:
	sc_int<8> data1, in_data;
	sc_event nw_e1;
	
	SC_HAS_PROCESS(PrintUnit);
	
	PrintUnit(sc_module_name name) : sc_module(name) {
		SC_METHOD(print);
		cout << "[Print unit]      | <" << sc_time_stamp() << "> | Online" << endl;
		dont_initialize();
		sensitive << nw_e1;
	}

	void print();
	void write_ch1(sc_int<8> data);
	sc_int<8> read_ch1();
};
#endif