#include <iostream>
#include "systemc.h"
#include "transport.h"
#include "ship.h"
#include "product.h"
#include "send_building_if.h"
#include "send_human_if.h"
#include "send_product_if.h"
#include "building.h"

using namespace std;





int sc_main(int argc, char *argv[]) {
    simply_application app("APP");
    app.print();

    return (0);
}
