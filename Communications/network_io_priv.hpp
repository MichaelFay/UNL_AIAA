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

/*******************Global Variables******************************************/																			//network size

boolean _byte_full; 
boolean _packet_full;
boolean _crc_check_pass;
uint8 	_data_byte;
IMP 	_data_packet;
extern IMP * rx_buffer; 
extern IMP * tx_buffer; 

/*********************** Function Proto's ************************************/

class network_io
{
public:
	//network_io();
	//~network_io();
	void init();
	void sendPkt(IMP * pkt);
	void startRecieve();
	void stopRecieve();
	void setRecieveCallback(); 

private: 
	void writeByte(void * byte);
	void networkWritePacket(IMP * pkt);
	void bitRecieve();
};

#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
