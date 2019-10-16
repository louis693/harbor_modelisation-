#include "transport.h"
void transport::send_human()
{
    cout<<sc_time_stamp().to_string()<<"\t"<<"Transport got human!"<<endl;
}

void transport::send_product()
{
    cout<<sc_time_stamp().to_string()<<"\t"<<"Building got product!"<<endl;
}

void transport::send_building(const int data)
{
    cout<<sc_time_stamp().to_string()<<"Transport got refuel from building."<<endl;
  //  cout<<""
}

SC_CTOR(transport){
    cout<<"Transport was created!"<<endl
};
