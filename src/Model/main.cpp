#include "systemc.h"
#include "harbor.h"
#include <iostream>

int sc_main(int argc, char *argv[]) {
	std::cout << std::endl << "__Start initialation___" << std::endl;
    harbor Petersburg("Main_Harbor");
	std::cout << std::endl << "__Start Simulation____" << std::endl;
    sc_start(200, SC_NS);
	std::cout << std::endl << "__End Simulation____" << std::endl;
    return 0;
}
