#include "ship.h"
void ship::send_human()
{
    cout<<sc_time_stamp().to_string()<<"\t"<<"Transport got human!"<<endl;
}

SC_CTOR(ship){
    cout<<"Ship was created!"<<endl
};
