#include "systemc.h"
#include <iostream>
#include <random>

#include "harbor.h"

using namespace std;

int sc_main(int argc, char *argv[]) {
    harbor Petersburg("Main_Harbor");
    sc_start(200, SC_NS);
    return 0;
}
