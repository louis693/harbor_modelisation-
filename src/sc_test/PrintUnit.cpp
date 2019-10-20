/*
* Ѕлок ¬ывода Ц PrintUnit Ц блок, который выводит число, полученное от блока проверки последнего байта,
* на экран в двоичном и дес€тичном виде.
* „исло поступает в PrintUnit в виде пакета, имеющего длину 1 байт,
* за которым следует специальный символ признак конца пакета EOP.

@version 1.0
@date 25.12.2017
@authors  узнецов ƒмитрий
*/
#include "PrintUnit.h"

void PrintUnit::print() {
	//_METHOD	
	cout << "[Print unit]      | <" << sc_time_stamp() << "> | Read CH1 = " << in_data <<endl;
	in_data = read_ch1(); 	
	cout << "[Print unit]      | <" << sc_time_stamp() << "> | Print = " <<in_data<<"(10) ";
	for (int i = 0; i < 8; i++)cout << in_data[7 - i];
	cout << "(2)" << endl;
	
}
void PrintUnit::write_ch1(sc_int<8> data) {
	data1 = data;
	nw_e1.notify();
}
sc_int<8> PrintUnit::read_ch1() {
	return data1;
}