#include "init.h"

void init_osc();
void init_global();
void init_PPS();
void init_interrupt();

void start()
{
    init_osc();
    init_global();
    init_PPS();
    init_CLCs();
    init_CMP_DAC();
    init_ADC();
    init_TMRs();
    init_interrupt();
}

void init_osc()
{
    // NOSC EXTOSC; NDIV 1; 
    OSCCON1 = 0x70;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 4_MHz; 
    OSCFRQ = 0x02;
    // MFOR not ready; 
    OSCSTAT = 0x00;
    // HFTUN 0; 
    OSCTUNE = 0x00;
}

void init_global()
{
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0xFF;
    LATE = 0x00;
    
    //Refer to schem
    TRISA = 0b11000111;
    TRISB = 0b11111110;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000001;

    ANSELA = 0x04;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;

    WPUA = 0x03;
    WPUB = 0xE0;
    WPUC = 0x00;
    WPUD = 0x00;
    WPUE = 0x00;
    
    //Open drain
    ODCONE = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;
    ODCOND = 0x00;
}

void init_PPS()
{
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    T5CKIPPSbits.T5CKIPPS = 0x00;   //RA0->TMR5:T5CKI;
    CLCIN0PPS = 0x00;   //RA0->CLCx:CLCIN0;
    CLCIN1PPS = 0x01;   //RA1->CLCx:CLCIN1;
    RA4PPS = 0x01;   //RA4->CLC1:CLC1OUT;
    RA3PPS = 0x02;   //RA3->CLC2:CLC2OUT;
    RB0PPS = 0x03;   //RB0->CLC3:CLC3OUT;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS
}

void init_interrupt()
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
}