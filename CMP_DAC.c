#include "CMP_DAC.h"

void (*CMP1_InterruptHandler)(void);

void init_CMP_DAC()
{
    // DAC1EN enabled; NSS VSS; DAC1PSS0 VDD; OE1 disabled; OE2 disabled; 
    DAC1CON0 = 0x80;
    // DAC1R 22; (68%)
    DAC1CON1 = DAC_68;
    
    PIE2bits.C1IE = 0;
    // set the CMP to the options selected in MPLAB(c) Code Configurator
    // C1HYS disabled; C1ON enabled; C1POL not inverted; C1SYNC asynchronous;                          
    CM1CON0 = 0x80;
    // C1INTN intFlag_neg; C1INTP no_intFlag;                          
    CM1CON1 = 0x01;
    // C1NCH CIN3-;                          
    CM1NSEL = 0x03;
    // C1PCH DACOUT;                          
    CM1PSEL = 0x05;
    // Clearing IF flag before enabling the interrupt.
    PIR2bits.C1IF = 0;
    // Enabling CMP1 interrupt.
    //PIE2bits.C1IE = 1;
}

inline bool getCMP1out(void)
{
    return (CMOUTbits.MC1OUT);
}

void CMP1_ISR(void)
{
    // clear the CMP1 interrupt flag
    T3CONbits.TMR3ON = 0; //Quick ! stop it !
    PIR2bits.C1IF = 0;
    setCMP1Interrupt(false);
    
    if(CMP1_InterruptHandler)
    {
        CMP1_InterruptHandler();
    }
}

void setCMP1InterruptHandler(void* InterruptHandler)
{
    CMP1_InterruptHandler = InterruptHandler;
}

void setCMP1Interrupt(bool useInt)
{
    PIR2bits.C1IF = 0;
    PIE2bits.C1IE = useInt;
}