#include <xc.h>
#include "CMP_DAC.h"
#include "TMR.h"

void interrupt INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCONbits.PEIE == 1 && PIE2bits.C1IE == 1 && PIR2bits.C1IF == 1)
    {
        CMP1_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE5bits.TMR5GIE == 1 && PIR5bits.TMR5GIF == 1)
    {
        PIR5bits.TMR5GIF=0; PIE5bits.TMR5GIE =0;//TMR5_GATE_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE4bits.TMR1IE == 1 && PIR4bits.TMR1IF == 1)
    {
        TMR1_ISR();
    }
    else if(INTCONbits.PEIE == 1 && PIE4bits.TMR3IE == 1 && PIR4bits.TMR3IF == 1)
    {
        TMR3_ISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}
