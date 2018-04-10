#include "TMR.h"

volatile bool isTMR3fast;

void (*TMR1_InterruptHandler)(void);
void (*TMR3_InterruptHandler)(void);
void (*TMR5_InterruptHandler)(uint16_t);

void init_TMR1(void);
void init_TMR3(void);
void init_TMR5(void);

void init_TMRs()
{
    init_TMR1();
    init_TMR3();
    init_TMR5();
}

//The gated thing seems not working, so... soft
void startGatedCount(bool fast)
{
    //Stop
    T3CONbits.TMR3ON = 0;
    T5CONbits.TMR5ON = 0;
    
    //Change TMR3 prescaler and start value
    isTMR3fast = fast;
    if(fast){
        T3CON = 0x02; // to 1:1
        TMR3L = (unsigned char) (TMR3_FAST);
        TMR3H = TMR3_FAST>>8;
    }
    else{
        T3CON = 0x32; // to 1:8
        TMR3L = (unsigned char) (TMR3_SLOW);
        TMR3H = TMR3_SLOW>>8;
    }
    
    //Load proper values
    TMR5H = 0x00;
    TMR5L = 0x00;
    
    //Clear flags
    PIR4bits.TMR3IF = 0;
    PIR5bits.TMR3GIF = 0;
    PIR4bits.TMR5IF = 0;
    PIR5bits.TMR5GIF = 0;
    
    //Start both timer and counter
    T3CONbits.TMR3ON = 1;
    T5CONbits.TMR5ON = 1;
    setTMR3Interrupt(true);
}

void startTimeMeasurement(void)
{
    //Stop
    T3CONbits.TMR3ON = 0;
    T5CONbits.TMR5ON = 0;
    
    //Change TMR3 prescaler to 1:1
    T3CON = 0x02;
    isTMR3fast = true;
    
    //Load proper values
    TMR3H = 0x00;
    TMR3L = 0x00;
    
    //Clear flags
    PIR4bits.TMR3IF = 0;
    PIR5bits.TMR3GIF = 0;
    
    //Start timer
    T3CONbits.TMR3ON = 1;
    setTMR3Interrupt(true);
}

/*
 * Timer 1 functions
 */

void init_TMR1(void)
{
    //CKPS 1:1; nT1SYNC synchronize; TMR1ON off; T1RD16 enabled; 
    T1CON = 0x02;
    //T1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON = 0x00;
    //GSS T1G; 
    T1GATE = 0x00;
    //CS FOSC/4; 
    T1CLK = 0x01;
    //TMR1H 231; 
    TMR1H = TMR1_RELOAD_H;
    //TMR1L 150; 
    TMR1L = TMR1_RELOAD_L;

    // Clearing IF flag before enabling the interrupt.
    PIR4bits.TMR1IF = 0;

    // Enabling TMR1 interrupt.
    PIE4bits.TMR1IE = 1;

    // Start TMR1
    T1CONbits.TMR1ON = 1;
}

void TMR1_ISR(void)
{
    // Clear the TMR1 interrupt flag
    PIR4bits.TMR1IF = 0;

    TMR1H = TMR1_RELOAD_H;
    TMR1L = TMR1_RELOAD_L;

    if(TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();
    }
}

void setTMR1InterruptHandler(void* InterruptHandler)
{
    TMR1_InterruptHandler = InterruptHandler;
}

void setTMR1Interrupt(bool useInt)
{
    PIR4bits.TMR1IF = 0;
    PIE4bits.TMR1IE = useInt;
}

/*
 * Timer 3 functions
 */

void init_TMR3(void)
{
    //CKPS 1:8; nT3SYNC synchronize; TMR3ON off; T3RD16 enabled; 
    T3CON = 0x32;
    //T3GE disabled; T3GTM disabled; T3GPOL low; T3GGO done; T3GSPM disabled; 
    T3GCON = 0x00;
    //GSS T3G; 
    T3GATE = 0x00;
    //CS FOSC/4; 
    T3CLK = 0x01;
    //TMR3H 231; 
    TMR3H = 0x00;
    //TMR3L 150; 
    TMR3L = 0x00;

    // Clearing IF flag.
    PIR4bits.TMR3IF = 0;
    
    //Stop TMR3
    T3CONbits.TMR3ON = 0;
}

void setTMR3(uint16_t timerVal)
{
    TMR3H = (timerVal >> 8);
    TMR3L = (unsigned char) timerVal;
}

uint16_t getTMR3(void)
{
    uint16_t readVal;

    T3CONbits.TMR3ON = 0;
    readVal = ((uint16_t)TMR3L);
    readVal |= (((uint16_t)TMR3H) << 8);

    return readVal;
}

void TMR3_ISR(void)
{
    static byte count=0;
    //Stop
    T3CONbits.TMR3ON = 0;
    //Clear flags
    PIR4bits.TMR3IF = 0;
    PIR5bits.TMR3GIF = 0;
    PIR4bits.TMR5IF = 0;
    PIR5bits.TMR5GIF = 0;
    
    if(!isTMR3fast){ //Then we have to slow it even more
        TMR3L = (unsigned char) (TMR3_SLOW);
        TMR3H = TMR3_SLOW>>8;
        
        count++;
        if(count >= TMR3_COUNT){
            count = 0;
        }
        else{
            T3CONbits.TMR3ON = 1; //Lets go !
            return;
        }
    }
    
    //Stop here
    T5CONbits.TMR5ON = 0;
    setTMR3Interrupt(false);
    
    setTMR3(0xFFFF);
    
    if(TMR3_InterruptHandler)
    {
        TMR3_InterruptHandler();
    }
}

void setTMR3InterruptHandler(void* InterruptHandler)
{
    TMR3_InterruptHandler = InterruptHandler;
}

void setTMR3Interrupt(bool useInt)
{
    PIR4bits.TMR3IF = 0;
    PIE4bits.TMR3IE = useInt;
}

/*
 * Timer 5 functions
 */

void init_TMR5(void) //Changed to normal counter
{
    //CKPS 1:1; nT5SYNC do_not_synchronize; TMR5ON off; T5RD16 enabled; 
    T5CON = 0x06;
    //T5GE (dis)enabled; T5GTM disabled; T5GPOL low; T5GGO done; T5GSPM enabled; 
    T5GCON = 0x10; //0x90
    //GSS TMR3_Overflow; 
    T5GATE = 0x04; //whatever, not used
    //CS T5CKI; 
    T5CLK = 0x00;
    //TMR5H 0; 
    TMR5H = 0x00;
    //TMR5L 0; 
    TMR5L = 0x00;

    // Clearing IF flag.
    PIR4bits.TMR5IF = 0;

    // Clearing IF flag
    PIR5bits.TMR5GIF = 0;
    
    //Stop Counter 5
    T5CONbits.TMR5ON = 0;
}

uint16_t getTMR5(void)
{
    uint16_t readVal;

    T5CONbits.TMR5ON = 0;
    readVal = ((uint16_t)TMR5L);
    readVal |= (((uint16_t)TMR5H) << 8);

    return readVal;
}
