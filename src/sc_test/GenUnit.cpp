/**
* √енератор пакетов Ц GenUnit Ц блок, который формирует два пакета.
* ѕакет представл€ет собой массив типа sc_int. –азр€дность каждого элемента в массиве равна 8 бит.
* Ёлементы пакета заполн€ютс€ случайными числами в диапазоне от 0 до +127. GenUnit побайтно передает два массива в блок —умматор.
* ƒлина каждого пакета задаетс€ параметрически через конструктор класса NetworkUnit.
* NetworkUnit передает эти параметры классу GenUnit до запуска моделировани€.
* ѕериодичность отправки байт вычисл€етс€ из скорости передачи данных по сети.
*  ак только был отправлен последний байт массива, GenUnit отправл€ет специальный байт, имеющий тот же тип, что и массивы.
* Ётот специальный байт имеет значение 255 и означает, что был передан весь пакет (EOP).

@version 1.0
@date 25.12.2017
@authors  узнецов ƒмитрий
*/
#include "GenUnit.h"
#include "nwinterface.h"

void GenUnit::gen() {
	pkg1 = new sc_int<8>[m_len1];
	pkg2 = new sc_int<8>[m_len2];
	srand(11);
	int i = 0;
	while (m_len1 >= i || m_len2 >= i) {

		if (m_len1 > i) {
			pkg1[i] = rand() % 128;
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Number generated = " << pkg1[i] << endl;
			gen_out_1->write_ch1(pkg1[i]);
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Send CH1 = " << pkg1[i] << endl;
		}
		else if (m_len1 == i){
			gen_out_1->write_ch1(255);
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Send CH1 = EOP" << endl;
		}
	/*
		if (m_len2 > i) {
			pkg2[i] = rand() % 128;
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Number generated = " << pkg2[i] << endl;
			gen_out_2->write_ch2(pkg2[i]);
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Send CH2 = " << pkg2[i] << endl;
		}
		else if (m_len2 == i){
			gen_out_2->write_ch2(255);
			cout << "[Gen unit]        | <" << sc_time_stamp() << "> | Send CH22 = EOP" << endl;
		}
		*/
		i++;
		wait(2, SC_NS);
	}
}
void GenUnit::write_ch1(sc_int<8> data) {
	data1 = data;
	nw_e1.notify();
}
void GenUnit::write_ch2(sc_int<8> data) {
	data2 = data;
	nw_e2.notify();
}
sc_int<8> GenUnit::read_ch2() {
	return data2;
}
sc_int<8> GenUnit::read_ch1() {
	return data1;
}

