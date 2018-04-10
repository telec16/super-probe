#ifndef UTILS_H
#define	UTILS_H

#include "config.h"

#include <xc.h>
#include <pic16f18877.h>

/*
 * PIN MACROs
 */
#define _SET_DISPLAY(d) LATD = ~(1<<(d));
#define _SET_SEGMENT(s) LATC = (s);
#define _SET_MEASURE(m) LATEbits.LATE1=(m) ? 0:1;
#define _SET_OUTPUT(o)  LATEbits.LATE2=(o) ? 0:1;

#define _MEASURE_DIR(d)     TRISB = ((d)&0x1E) | (TRISB&0xE1);
#define _MEASURE_SET(d, v)  LATB = (((v) ? (d):0) | (LATB&(~(d))));
#define _MEASURE_GET(d)     ((PORTB&(d)) ? 1:0)

#define _GET_MODE (!PORTBbits.RB7)
#define _GET_UP   (!PORTBbits.RB6)
#define _GET_DN   (!PORTBbits.RB5)
#define _GET_PIN  (PORTAbits.RA0)

#define _USE_DEBUG(u)   TRISAbits.TRISA5 = (u) ? 0:1;
#define _TOGGLE_DEBUG   LATAbits.LATA5 ^= 1;

/*
 * MACRO
 */
#define _MIN(a,b)   (((a)<(b)) ? (a):(b))
#define _MAX(a,b)   (((a)>(b)) ? (a):(b))
#define _ABS(a)     (((a)< 0 ) ? -(a) : (a))

/*
 * Global variables
 */
extern volatile byte display[DISPLAYS];


#define write(a) writeo(a, 0);

/**
 * @description: Print a string on screen (with offset)
 *               Use write for no offset (start=0)
 * 
 * @params: -a: the string to be printed
 *          -start: offset, if < 0, start from the end of the string
 */
void writeo(const char* a, sbyte start);


#endif	/* UTILS_H */

