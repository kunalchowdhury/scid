/*
 * message_sender.h
 *
 * Created: 6/14/2016 4:52:00 PM
 *  Author: Ireena
 */ 


#ifndef MESSAGE_SENDER_H_
#define MESSAGE_SENDER_H_



class message_sender
{
public:
   message_sender();
   ~message_sender();
   zigbee_transmit_request& init_zb_tx_request(uint8_t msg_length, uint8_t frame_type);
   uint8_t * serial_payload(zigbee_transmit_request& req, bool is_slave_query);
private:	
   zigbee_transmit_request p_zb_tx_req;
    


};



#endif /* MESSAGE_SENDER_H_ */