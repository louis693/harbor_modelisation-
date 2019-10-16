#include "product.h"
void product::send_human()
{
    cout<<sc_time_stamp().to_string()<<"\t"<<"Transport got human!"<<endl;
}

SC_CTOR(product){
    cout<<"product was created!"<<endl
};
