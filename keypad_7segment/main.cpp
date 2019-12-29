/*
 * keypad_7segment.cpp
 *
 * Created: 12/26/2019 4:23:34 AM
 * Author : Formulatrix
 */ 

#include <avr/io.h>
#include "src/AvrGpio.h"
#include "src/AvrSpi.h"
#include "src/AvrTimer.h"
#include "src/HeartBeat.h"
#include "src/PinMapping.h"
#include "src/Keypad.h"
#include "src/SevenSegment.h"

int main(void)
{
	// heartbeat init
    CHeartBeat heartBeat;
    CAvrGpio led;
    CAvrTimer timer;
	led.Init(PIN_HEARTBEAT,1);
	timer.Init(CAvrTimer::psc256);
	heartBeat.Init(&led,&timer,30000);
	
	// keypad init
	// initialize the gpio
    CKeypad keypad;
    CAvrGpio rowPin[4];
    CAvrGpio colPin[4];
	rowPin[0].Init(PIN_ROW0,1);
	rowPin[1].Init(PIN_ROW1,1);
	rowPin[2].Init(PIN_ROW2,1);
	rowPin[3].Init(PIN_ROW3,1);
	colPin[0].Init(PIN_COL0,0);
	colPin[1].Init(PIN_COL1,0);
	colPin[2].Init(PIN_COL2,0);
	colPin[3].Init(PIN_COL3,0);
	keypad.Init(rowPin,colPin);

	// display init
    CSevenSegment display;
    CAvrSpi spi;
    CAvrGpio pin;
    pin.Init(PIN_MOSI,1);
    pin.Init(PIN_SCK,1);
    pin.Init(PIN_SS,1);	
    spi.Init(&pin,CAvrSpi::psc2,0,0);
    display.Init(&keypad,&spi);

    while (1) 
    {
        heartBeat.Execute();
        display.Execute();
    }
}

