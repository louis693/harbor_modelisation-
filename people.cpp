#include "people.h"

void people::human_generator(){
    while(true){
        hum_to_ship->send_human();
        hum_to_transport->send_human();
        hum_to_building->send_human();

        wait(1,SC_NS);
    }
}

SC_CTOR(people){
    cout<<"Human created!"<<endl;
    SC_THREAD(human_generator)
};
