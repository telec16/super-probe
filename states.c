#include "states.h"

uint16_t measureInput();
uint16_t measureTemp();

/*
 * voltmeter_state
 */
void voltmeter_state()
{
    char buf[17];
    int m = measureInput();

    sprintf(buf, "%06.03f  v", m/1000.0);
    write(buf);

    __delay_ms(100);
}

uint16_t measureInput()
{
    adc_result_t r;
    
    _SET_MEASURE(1);
    r = ADC_GetSingleConversion(channel_ANA2);
    _SET_MEASURE(0);
    
    return (uint16_t)(((double)r)*INPUT_MULT);
}

/*
 * freqmeter_state
 */
volatile bool fast = false;

void freqmeter_state()
{
    if(_GET_DN){
        //Debounce & wait
        __delay_ms(1);
        while(_GET_DN);

        fast = !fast;
    }
    
    startGatedCount(fast);
    
    //Wait the interrupt
}

void printFreq()
{
    char buf[17];
    uint16_t count = getTMR5();
    
    if(fast){
        sprintf(buf, "%06.01fkhz", count/10.0);
    }
    else{
        sprintf(buf, "%05d hz", count);
    }
    write(buf);
}

/*
 * counter_state
 */
void counter_state()
{
    static uint16_t count=0;
    static byte lPin = 0;
    char buf[17];
    byte pin;
    
    if(_GET_DN)
        count=0;
    
    pin = _GET_PIN;
    if((pin == 1) && (pin != lPin))
        count++;
    
    lPin = pin;
        
    sprintf(buf, "c %06d", count);
    write(buf);
}

/*
 * tempmeter_state
 */
void tempmeter_state()
{
    char buf[17];
    int m = _ABS((int)measureTemp());

    sprintf(buf, "%+06.02f *c", m/1000.0);
    write(buf);

    __delay_ms(100);
}

uint16_t measureTemp()
{
    adc_result_t r;
    FVRCONbits.TSEN = 1;
    FVRCONbits.TSRNG = 1;
    
    r = ADC_GetSingleConversion(channel_Temp);
    
    return (uint16_t)(((double)r)*TEMP_MULT + TEMP_ADD);
}

/*
 * capameter_state
 * Enable output circuitry, then discharge capa (via 330)
 * enable interrupt and start timer, then charge capa (via 1K)
 * 
 * TODO: add mode for smaller cap (higher res)
 */
void capameter_state()
{    
    _SET_OUTPUT(1);
    _MEASURE_DIR(_USE(R330 | R1K))
    _MEASURE_SET(R330, 0) //Actually generating some code
    _MEASURE_SET(R1K, 0)
    __delay_ms(5);//Discharge time
    _MEASURE_DIR(_USE(R1K))
    
    
    setCMP1Interrupt(true);
    startTimeMeasurement();
    _MEASURE_SET(R1K, 1)
    
    //Wait the interrupt
}

void printCapa()
{
    static uint16_t offset = 0;
    char buf[17];
    uint16_t tmr = getTMR3();
    
    if(_GET_DN){
        //Debounce & wait
        __delay_ms(1);
        while(_GET_DN);

        offset = tmr;
    }
    if(tmr>offset) tmr -= offset;
    else tmr = 0;
    
    //Magical calculus in here
    //sprintf(buf, "f 0x%04x", tmr);//debug
    tmr = (uint16_t)(((double)tmr) * CAPA_MULT_1K);
    sprintf(buf, "%06.03f uf", tmr/1000.0);
    write(buf);
}


void resmeter_state()
{
    write("resmeter_state");
}

void pwm_state()
{
    write("pwm_state");
    //NCO
}

void ibtn_state()
{
    write("ibtn_state");
}