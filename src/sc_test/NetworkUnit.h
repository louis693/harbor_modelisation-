#include "systemc.h"

#include "GenUnit.h"
#include "SumUnit.h"
/*#include "CheckByteUnit.h"
#include "PrintUnit.h"*/

#ifndef H_NETWORKUNIT
#define H_NETWORKUNIT


class  NetworkUnit : sc_module {
public:
	GenUnit *generator;
	SumUnit *summator;
/*	CheckByteUnit *CB;
	PrintUnit *print;
	*/

	sc_event network_e;
	sc_clock C1;
	NetworkUnit(sc_module_name name) : sc_module(name),		
									   C1("C1"),	
									   generator(new GenUnit("Generator1", 5,8)),		
									//   CB(new CheckByteUnit("Check1")),		
									   summator(new SumUnit("Summator1"))		
									 //  print(new PrintUnit("Print1")) 	
	{
		cout << "[Network unit]    | <" << sc_time_stamp() << "> | Online" << endl;
		cout << "[Network unit]    | <" << sc_time_stamp() << "> | Bind port gen_out_1->Sum Unit" << endl;
		generator->gen_out_1.bind(*summator);
		/*cout << "[Network unit]    | <" << sc_time_stamp() << "> | Bind port gen_out_2->Sum Unit" << endl;
		generator->gen_out_2.bind(*summator);
		cout << "[Network unit]    | <" << sc_time_stamp() << "> | Bind port sum_out->CheckByte Unit" << endl;
		summator->sum_out.bind(*CB);
		cout << "[Network unit]    | <" << sc_time_stamp() << "> | Bind port cb_out->Print Unit" << endl;
     	CB->cb_out.bind(*print);
		*/
		generator->clock(C1);
	}
	~NetworkUnit() {
		if (generator) { delete generator; generator = 0; }
		if (summator) { delete summator; summator = 0; }
		/*if (CB) { delete CB; CB = 0; }
		if (print) { delete print; print = 0; }*/
	}
};
#endif
