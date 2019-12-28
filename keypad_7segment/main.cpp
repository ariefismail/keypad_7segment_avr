/*
 * keypad_7segment.cpp
 *
 * Created: 12/26/2019 4:23:34 AM
 * Author : Formulatrix
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "src/AvrGpio.h"
#include "src/AvrSpi.h"
#include "src/AvrTimer.h"
#include "src/HeartBeat.h"

int main(void)
{
    /* Replace with your application code */
	CAvrGpio led;
	CAvrTimer timer;
	CAvrSpi spi;
	CHeartBeat heartBeat;
	led.Init(&PINB,0,1);
	timer.Init(CAvrTimer::psc256);
	heartBeat.Init(&led,&timer,30000);
	
    while (1) 
    {
		heartBeat.Execute();
    }
}

