#ifndef TMR_H
#define	TMR_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "config.h"

//0xE796 -> 1kHz @ 25MHz/4
#define TMR1_RELOAD_H 0xE7
#define TMR1_RELOAD_L 0x96
//0x676A -> 20Hz @ 25MHz/34   0x0BDC -> 100Hz @ 25MHz/4
#define TMR3_SLOW 0x6769
#define TMR3_FAST 0x0BDC
#define TMR3_COUNT 20

void init_TMRs();
void startGatedCount(bool fast);
void startTimeMeasurement(void);

//TMR1
void setTMR1InterruptHandler(void* InterruptHandler);
void setTMR1Interrupt(bool useInt);

//TMR3
void setTMR3(uint16_t timerVal);
uint16_t getTMR3(void);
void setTMR3InterruptHandler(void* InterruptHandler);
void setTMR3Interrupt(bool useInt);

//TMR5
uint16_t getTMR5(void);

//Do not call
void TMR1_ISR(void);
void TMR3_ISR(void);

#endif	/* TMR_H */

