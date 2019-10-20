/*
	* �������� � SumUnit � ����, ������� ����������� ��������� ���������� �� GenUnit ��� ������.
	* SumUnit �������� ����������� �������� ���� ������� ������ � ��� ������,
	* ���� ��� ����� ������� ���� �������� ��� ����������� ����� EOP.
	* ��������� ������������ � ����� � ���������� �� ��������� ���������� ����� � ����� �������� ���������� �����.
	* ���� SumUnit ���������� ����������� ���� EOP ����� �������� ���������� ����� ��������������� ������.
	* ���� ������ ����� ������ �����, �� ����� �������� ����� ����������� ������.
	* ������ ����� ����� ����������� ������������.

	@version 1.0
	@date 25.12.2017
	@authors �������� �������
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
