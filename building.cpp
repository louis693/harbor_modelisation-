#include "building.h"
void building::send_human()
{
    cout<<sc_time_stamp().to_string()<<"\t"<<"Transport got human!"<<endl;
}

building::SC_CTOR(building){
    cout<<"building was created!"<<endl
};
