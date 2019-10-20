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
	staff *m_staff;
    FishShip *m_FishShip;
	sc_clock workclock;

	
	harbor(sc_module_name name) : sc_module(name),
		workclock ("Work_Day"),
		m_staff(new staff ("Staff")),
        m_FishShip(new FishShip ("FishShip"))
    {
		
		m_FishShip->tx_fish_to_staff_port.bind(*m_staff);
		m_FishShip->schedule(workclock);
     
    }
	
    ~harbor() {
        if (m_FishShip) { delete m_FishShip; m_FishShip = nullptr; }
        if (m_staff) { delete m_staff; m_staff = nullptr; }       
    }
	
};
#endif
