#ifndef harbor_h
#define harbor_h
#include "systemc.h"

#include "people.h"
#include "building.h"
#include "product.h"
#include "ship.h"
#include "transport.h"


class harbor : public sc_module {
public:
    fish_ship *m_fish_ship;
    staff *m_staff;
    /*
      radio_base *m_radio_base;
      truck *m_truck;
      warehouse *m_warehouse;
    */


    /*
    SC_CTOR(harbor) : m_fish_ship("fish_ship"), m_radio_base("radio_base"), m_staff("staff"), m_truck("truck"), m_warehouse("warehouse") {
        cout << "Harbor was created!" << endl;
        // fish_ship binding

        m_fish_ship.tx_message_to_radio_base_port(m_radio_base);
        m_fish_ship.tx_fish_to_staff_port(m_staff);


        // radio_base binding
        m_radio_base.tx_message_to_staff_port(m_staff);

        // staff binding
        m_staff.tx_message_to_fish_ship_port(m_fish_ship);
        m_staff.tx_fish_to_truck_port(m_truck);

        // truck binding
        m_truck.tx_message_to_staff_port(m_staff);
        m_truck.tx_fish_to_warehouse_port(m_warehouse);

};
*/

    harbor(sc_module_name name) : sc_module(name),
        m_fish_ship(new fish_ship("Fish_ship")),
        m_staff(new staff("Staff"))
     /*
        m_radio_base(new radio_base("Radio_base")),
        m_truck(new truck("Truck")),
        m_warehouse(new warehouse("warehouse")),
      */
    {
        m_fish_ship->tx_fish_to_staff_port.bind(*m_staff);
       /* generator->gen_out_2.bind(*summator);
        summator->sum_out.bind(*CB);
        CB->cb_out.bind(*print);*/
    }
    ~harbor() {
        if (m_fish_ship) { delete m_fish_ship; m_fish_ship = nullptr; }
        if (m_staff) { delete m_staff; m_staff = nullptr; }
       /*
        if (m_radio_base) { delete m_radio_base; m_radio_base = 0;
        if (m_truck) { delete m_truck; m_truck = 0; }
        if (m_warehouse) { delete m_warehouse; m_warehouse = 0; }
        */
    }
};
#endif
