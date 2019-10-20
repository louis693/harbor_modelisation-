/*
* ���� �������� ���������� ����� � CheckByteUnit � ����, �������������� ��������� ������������ �� ��������� ������.
* CheckByteUnit ������������ ���������� 1-��� (����� �� ��������� �1�) � ��������� ����� ������.
* ���� ���������� ��� � ������, �� CheckByteUnit ���������� �������� �����, ��������� �� ������ ����� �� ��������� 100
* ����� ������ PrintUnit, ����� ��������������� EOP. � ��������� ������, CheckByteUnit ���������� ���� �� ��������� 0.

@version 1.0
@date 25.12.2017
@authors �������� �������
*/
#include "CheckByteUnit.h"
#include "nwinterface.h"

void CheckByteUnit::check() {
	//THREAD		

	while (true) {
		count = 0;
		pkg = read_ch1();
		cout << "[Check byte unit] | <" << sc_time_stamp() << "> | Read CH1 = " <<pkg << endl;
		for (int i = 0; i < 8; i++) if ((pkg[i] & 1) == 1) count++;
		cout<< "[Check byte unit] | <" << sc_time_stamp() << "> | Bits count = " << count << endl;
		count % 2 == 0 ? count = 100 : count = 0;
		cout << "[Check byte unit] | <" << sc_time_stamp() << "> | Send CH1 = " << count << endl;
		cb_out->write_ch1(count);
		wait(nw_e1);
	}
}
void CheckByteUnit::write_ch1(sc_int<8> data) {
	data1 = data;
	nw_e1.notify();
}
sc_int<8> CheckByteUnit::read_ch1() {
	return data1;
}