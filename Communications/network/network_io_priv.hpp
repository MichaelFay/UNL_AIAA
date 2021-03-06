/*****************************************************************************
*********************Syncronization Library for Atmega 2560*******************
******************************************************************************

Developed By: Michael Fay for Rocksat-X 2016

File Name:
Last revised:
Version Number:

Tested By:
Last Tested:
******************************************************************************/

#ifndef __NETWORK_IO_H__
#define __NETWORK_IO_H__

/******************************* Includes ************************************/
#include "bsp.h"
#include "packet_def.hpp"
#include "primative.hpp"
/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/

/*******************Global Variables******************************************/																			
boolean _byte_full; 
boolean _packet_full;
boolean _crc_check_pass;
boolean  pkt_failed; 

uint8 	_rx_data_buffer[MAX_RX_DATA_STREAM]; 

uint8 	_pkt_data_overflow; 
uint8 	_rx_data_byte;
uint8 	_bits_recieved; 
uint8 	_pkt_location; 
uint8 	_network_type; 
uint8  	_data_stream_counter; 

callback _rx_callback_ftn;

NERI 	_data_packet;





extern  NERI    rx_pkt_buffer[RX_BUFFER_MAX]; 
extern  NERI    tx_pkt_buffer[TX_BUFFER_MAX]; 

extern 	uint8  rx_data_buffer[TX_DATA_BUFFER_MAX];
extern 	uint8  tx_data_buffer[RX_DATA_BUFFER_MAX];

extern  uint16 rx_current_bytes_writen; 

extern  void * current_rx_data_buffer_location;

extern 	RTC clock; 

extern 	logger log; 


/*********************** Function Proto's ************************************/

class network_io
{
public:
	//network_io();
	//~network_io();
	void init();
	void sendPkt(NERI * pkt);

	void startRecieve();
	void stopRecieve();
	void setPktRecieveCallback(); 
	//void sendPktWait(uint8 delay);

private: 

	void writeByte(void * byte);
	void wireWrite(NERI * pkt);
	void processPacket(); 
	void processDataStream();
	void wirebitRecieve();
};

#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
