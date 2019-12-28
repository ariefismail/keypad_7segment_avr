/* 
* AvrSpi.cpp
*
* Created: 12/26/2019 5:10:27 AM
* Author: Formulatrix
*/


#include "AvrSpi.h"

void CAvrSpi::Init(CAvrGpio *ssPin,Prescaler prescaler,uint8_t clockMode,uint8_t lsbFirst)
{
	m_ssPin=ssPin;
	m_ssPin->Set();
	
	// set clock speed and mode
	SPCR= (lsbFirst<<5) |((clockMode&0x3)<<2)  | (prescaler & 0x3);
	SPSR|=prescaler>>2
	
	// enable spi
	SPCR|=1<<6;
}
	
void CAvrSpi::Transfer(char *data,uint8_t size)
{
	for(uint8_t i=0;i<size;i++)
	{
		while( (SPIF>>7 & 1) == 0);
		SPDR=*data++;
	}
}

// default constructor
CAvrSpi::CAvrSpi()
{
} //AvrSpi

// default destructor
CAvrSpi::~CAvrSpi()
{
} //~AvrSpi
