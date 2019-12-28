/*
 * PinMapping.h
 *
 * Created: 12/28/2019 7:18:04 AM
 *  Author: Formulatrix
 */ 


#ifndef PINMAPPING_H_
#define PINMAPPING_H_

// misc
#define PIN_HEARTBEAT &PINB,0

// display related
#define PIN_LED &PINB,0
#define PIN_MOSI &PINB,5
#define PIN_SCK &PINB,7
#define PIN_SS &PINB,4

// keypad related
#define PIN_ROW0 &PINA,0
#define PIN_ROW1 &PINA,1
#define PIN_ROW2 &PINA,2
#define PIN_ROW3 &PINA,3
#define PIN_COL0 &PINC,0    
#define PIN_COL1 &PINC,1    
#define PIN_COL2 &PINC,2    
#define PIN_COL3 &PINC,3    


#endif /* PINMAPPING_H_ */