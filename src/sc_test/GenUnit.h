#include "systemc.h"
#include "nwinterface.h"

#ifndef H_GENUNIT
#define H_GENUNIT

class GenUnit :public sc_module, public nwinterface1/*, public nwinterface2*/ {
	sc_int<8> *pkg1, *pkg2;
	sc_int<8> m_len1, m_len2;
public:
	sc_in_clk clock;
	sc_int<8>  data1,data2;
	sc_event nw_e, nw_e1, nw_e2;
	sc_port <nwinterface1> gen_out_1;
//	sc_port <nwinterface2> gen_out_2;
	
	SC_HAS_PROCESS(GenUnit);
	GenUnit(sc_module_name name,sc_int<8> lenn1, sc_int<8> lenn2) : sc_module(name), m_len1(lenn1),m_len2(lenn2) {
		SC_THREAD(gen);
		cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Online" << endl;
		sensitive << clock.pos();
	}

	
	void write_ch1(sc_int<8> data1);
	void write_ch2(sc_int<8> data2);
	sc_int<8> read_ch1();
	sc_int<8> read_ch2();
	void gen();	
};
#endif
