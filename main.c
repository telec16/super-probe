/*
 * TMR1 : display refresh
 * TMR3 : measurement timer
 * TMR5 : gated counter
 */

/* TODO:
 * calibrer temp
 * 
 * changer comparateurs (sr dégeux + faux oc) -- OK
 * mode frequence b/h res 1Hz + 100Hz -- OK -- 255 max -- OK f*cking timer
 * fix timer+out capa --tmr to test -- OK
 * charset ! -- OK
 */

#include "config.h"

#include <xc.h>
#include <pic16f18877.h>
#include <stdlib.h>

#include "init.h"
#include "ADC.h"
#include "CLC.h"
#include "CMP_DAC.h"
#include "TMR.h"
#include "utils.h"
#include "states.h"

#define DEBUG_MODE 0

typedef enum{
    VOLTMETER,
    FREQMETER,
    COUNTER,
    TEMPMETER,
    CAPAMETER,
    RESMETER,
    PWM,
    IBTN_ID,
    STATES //<- this count the number of states
} state_t;

volatile byte display[DISPLAYS];
volatile bool freshNews = false;
volatile bool entering = true;

void refreshDisplay(void);
void computeFreq(void);
void computeCapa(void);

int main(void) 
{
    state_t state = VOLTMETER;
    
    setTMR1InterruptHandler(refreshDisplay);
    //setTMR5InterruptHandler(computeFreq);
    setCMP1InterruptHandler(computeCapa);
    
    start();
    
    setTMR1Interrupt(true);
    
    _SET_MEASURE(0);
    _SET_OUTPUT(0);
    _USE_DEBUG(1);
    
    write("telec u1");
    __delay_ms(500);
    
    while(1){
        
        switch(state){
            //IN stuff
            case VOLTMETER:
                voltmeter_state();
                break;
                
            case FREQMETER:
                if(entering){
                    freqmeter_state();
                    setTMR3InterruptHandler(computeFreq);
                }
                
                if(freshNews){
                    printFreq();
                    freshNews = false;
                    freqmeter_state();
                }
                
                break;
                
            case COUNTER:
                counter_state();
                break;
                
            case TEMPMETER:
                tempmeter_state();
                break;
            
            //OUT stuff
            case CAPAMETER:
                if(entering){
                    setTMR3InterruptHandler(computeCapa);
                    capameter_state();
                }
                
                if(freshNews){
                    printCapa();
                    freshNews = false;
                    capameter_state();
                }
                
                break;
                
            case RESMETER:
                resmeter_state();
                break;
                
            case PWM:
                pwm_state();
                break;
                
            case IBTN_ID:
                ibtn_state();
                break;
        }
        entering = false;
        
        if(_GET_MODE && !DEBUG_MODE){
            //Debounce & wait
            __delay_ms(1);
            while(_GET_MODE);
            
            state = (state+1) % STATES;
            entering = true;
        }
    }
    
    return 0;
}

void refreshDisplay(void)
{
    static byte d=0;
    
    _SET_SEGMENT(0)
    _SET_DISPLAY(d)
    _SET_SEGMENT(display[d])
    
    d = (d+1)%DISPLAYS;
}

void computeFreq(void)
{
    _TOGGLE_DEBUG
    freshNews = true;
}

void computeCapa(void)
{
    _SET_OUTPUT(0);
    _TOGGLE_DEBUG
    freshNews = true;
}
