#include "SumUnit.h"
#include "nwinterface.h"

void SumUnit::sum() {
	in_data1 = read_ch1();
	if (in_data1 == -1) {
		in_data1 = 0;
	cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Read CH1 imposible - EOP " << endl;
	}
	else

		cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Read CH1 = " << in_data1 << endl;
	
		
	in_data2 = read_ch2();
	if (in_data2 == -1) {
		in_data2 = 0;
		cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Read CH2 imposible - EOP " << endl;
	}
	else
	cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Read CH2 = " << in_data2 << endl;
	pkg = 0;
	pkg = in_data1 + in_data2;
	cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Sum: " << in_data1 <<" + " <<in_data2<<" = "<<pkg<< endl;
	cout << "[Sum unit]        | <" << sc_time_stamp() << "> | Send CH1 = " << in_data1 << endl;
	sum_out->write_ch1(pkg);
}
void SumUnit::write_ch0(sc_int<8> data) {
	data0 = data;
	nw_e0.notify();
}
void SumUnit::write_ch1(sc_int<8> data) {
	data1 = data;
	nw_e1.notify();
}
void SumUnit::write_ch2(sc_int<8> data) {
	data2 = data;
	nw_e2.notify();
}

sc_int<8> SumUnit::read_ch0() {
	return data0;
}
sc_int<8> SumUnit::read_ch1() {
	return data1;
}
sc_int<8> SumUnit::read_ch2() {
	return data2;
}