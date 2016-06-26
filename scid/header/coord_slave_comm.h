/*
 * coord_slave_comm.h
 *
 * Created: 6/12/2016 7:56:25 PM
 *  Author: Ireena
 */ 


#ifndef COORD_SLAVE_COMM_H_
#define COORD_SLAVE_COMM_H_


#include "inc.h"

class coordinator
{
public:
   coordinator();
   ~coordinator();
   void init(LCDDisplay& disp);
   void write_slave_addresses(LCDDisplay& disp, uint8_t idx, const uint8_t* address); // 64-bit
private:
   uint8_t** slaves_16_address;
   uint8_t** slaves_64_address;
   uint8_t  num_slaves;
   LCDDisplay display;
};



#endif /* COORD_SLAVE_COMM_H_ */