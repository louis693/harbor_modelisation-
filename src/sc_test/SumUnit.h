/*
	* —умматор Ц SumUnit Ц блок, который поэлементно суммирует полученные от GenUnit два пакета.
	* SumUnit начинает суммировать элементы двух пакетов только в том случае,
	* если дл€ обоих пакетов были получены оба специальных байта EOP.
	* –езультат суммировани€ Ц пакет Ц передаетс€ на обработку следующему блоку Ц блоку ѕроверки последнего байта.
	* Ѕлок SumUnit отправл€ет специальный байт EOP после отправки последнего байта результирующего пакета.
	* ≈сли пакеты имеют разную длину, то более короткий пакет дополн€етс€ нул€ми.
	* “олько после этого выполн€етс€ суммирование.

	@version 1.0
	@date 25.12.2017
	@authors  узнецов ƒмитрий
*/
#include "systemc.h"
#include "nwinterface.h"


#ifndef H_SUMUNIT
#define H_SUMUNIT
class  SumUnit :public sc_module, public nwinterface0, public nwinterface1, public nwinterface2 {
public:
	sc_port <nwinterface1> sum_out;
	sc_int<8> data0, data1, data2;
	sc_event nw_e0, nw_e1, nw_e2;

	sc_int <9> in_data1, in_data2;
	sc_int <9> pkg=0;

	SC_HAS_PROCESS(SumUnit);
	SumUnit(sc_module_name name) : sc_module(name) {
		SC_METHOD(sum);

		cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Online" << endl;
		dont_initialize();
		sensitive << nw_e1<<nw_e2;
	}

	void sum();
	void write_ch0(sc_int<8> data);
	void write_ch1(sc_int<8> data);
	void write_ch2(sc_int<8> data);

	sc_int<8> read_ch0();
	sc_int<8> read_ch1();
	sc_int<8> read_ch2();

};
#endif
