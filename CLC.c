#include "CLC.h"

void init_CLC1();
void init_CLC2();
void init_CLC3();
void init_CLC4();

void init_CLCs()
{
    init_CLC1();
    init_CLC2();
    init_CLC3();
    init_CLC4();
}

void init_CLC1()
{
    //CLC1 for H (H high and L low)
    // LC1G1POL not_inverted; LC1G2POL not_inverted; LC1G3POL not_inverted; LC1G4POL not_inverted; LC1POL not_inverted; 
    CLC1POL = 0x00;
    // LC1D1S CLCIN0 (CLCIN0PPS); 
    CLC1SEL0 = 0x00;
    // LC1D2S CLCIN1 (CLCIN1PPS); 
    CLC1SEL1 = 0x01;
    // LC1D3S CLCIN0 (CLCIN0PPS); 
    CLC1SEL2 = 0x00;
    // LC1D4S CLCIN0 (CLCIN0PPS); 
    CLC1SEL3 = 0x00;
    // LC1G1D3N disabled; LC1G1D2N disabled; LC1G1D4N disabled; LC1G1D1T disabled; LC1G1D3T disabled; LC1G1D2T disabled; LC1G1D4T disabled; LC1G1D1N enabled; 
    CLC1GLS0 = 0x02;//0x01
    // LC1G2D2N disabled; LC1G2D1N disabled; LC1G2D4N disabled; LC1G2D3N disabled; LC1G2D2T enabled; LC1G2D1T disabled; LC1G2D4T disabled; LC1G2D3T disabled; 
    CLC1GLS1 = 0x04;//0x08
    // LC1G3D1N disabled; LC1G3D2N disabled; LC1G3D3N disabled; LC1G3D4N disabled; LC1G3D1T disabled; LC1G3D2T disabled; LC1G3D3T disabled; LC1G3D4T disabled; 
    CLC1GLS2 = 0x00;
    // LC1G4D1N disabled; LC1G4D2N disabled; LC1G4D3N disabled; LC1G4D4N disabled; LC1G4D1T disabled; LC1G4D2T disabled; LC1G4D3T disabled; LC1G4D4T disabled; 
    CLC1GLS3 = 0x00;
    // LC1EN enabled; INTN disabled; INTP disabled; MODE AND-OR; 
    CLC1CON = 0x80;
}

void init_CLC2()
{
    //CLC2 for L (H low and L high)
    // LC2G1POL not_inverted; LC2G2POL not_inverted; LC2G3POL not_inverted; LC2G4POL not_inverted; LC2POL not_inverted; 
    CLC2POL = 0x00;
    // LC2D1S CLCIN0 (CLCIN0PPS); 
    CLC2SEL0 = 0x00;
    // LC2D2S CLCIN1 (CLCIN1PPS); 
    CLC2SEL1 = 0x01;
    // LC2D3S CLCIN0 (CLCIN0PPS); 
    CLC2SEL2 = 0x00;
    // LC2D4S CLCIN0 (CLCIN0PPS); 
    CLC2SEL3 = 0x00;
    // LC2G1D3N disabled; LC2G1D2N disabled; LC2G1D4N disabled; LC2G1D1T enabled; LC2G1D3T disabled; LC2G1D2T disabled; LC2G1D4T disabled; LC2G1D1N disabled; 
    CLC2GLS0 = 0x01;//0x02
    // LC2G2D2N enabled; LC2G2D1N disabled; LC2G2D4N disabled; LC2G2D3N disabled; LC2G2D2T disabled; LC2G2D1T disabled; LC2G2D4T disabled; LC2G2D3T disabled; 
    CLC2GLS1 = 0x08;//0x04
    // LC2G3D1N disabled; LC2G3D2N disabled; LC2G3D3N disabled; LC2G3D4N disabled; LC2G3D1T disabled; LC2G3D2T disabled; LC2G3D3T disabled; LC2G3D4T disabled; 
    CLC2GLS2 = 0x00;
    // LC2G4D1N disabled; LC2G4D2N disabled; LC2G4D3N disabled; LC2G4D4N disabled; LC2G4D1T disabled; LC2G4D2T disabled; LC2G4D3T disabled; LC2G4D4T disabled; 
    CLC2GLS3 = 0x00;
    // LC2EN enabled; INTN disabled; INTP disabled; MODE AND-OR; 
    CLC2CON = 0x80;
}

void init_CLC3()
{
    //CLC3 for Z (H and L are low)
    // LC3G1POL not_inverted; LC3G2POL not_inverted; LC3G3POL not_inverted; LC3G4POL not_inverted; LC3POL not_inverted; 
    CLC3POL = 0x00;
    // LC3D1S CLCIN0 (CLCIN0PPS); 
    CLC3SEL0 = 0x00;
    // LC3D2S CLCIN1 (CLCIN1PPS); 
    CLC3SEL1 = 0x01;
    // LC3D3S CLCIN0 (CLCIN0PPS); 
    CLC3SEL2 = 0x00;
    // LC3D4S CLCIN0 (CLCIN0PPS); 
    CLC3SEL3 = 0x00;
    // LC3G1D3N disabled; LC3G1D2N disabled; LC3G1D4N disabled; LC3G1D1T enabled; LC3G1D3T disabled; LC3G1D2T disabled; LC3G1D4T disabled; LC3G1D1N disabled; 
    CLC3GLS0 = 0x01;//0x02
    // LC3G2D2N disabled; LC3G2D1N disabled; LC3G2D4N disabled; LC3G2D3N disabled; LC3G2D2T enabled; LC3G2D1T disabled; LC3G2D4T disabled; LC3G2D3T disabled; 
    CLC3GLS1 = 0x04;//0x08
    // LC3G3D1N disabled; LC3G3D2N disabled; LC3G3D3N disabled; LC3G3D4N disabled; LC3G3D1T disabled; LC3G3D2T disabled; LC3G3D3T disabled; LC3G3D4T disabled; 
    CLC3GLS2 = 0x00;
    // LC3G4D1N disabled; LC3G4D2N disabled; LC3G4D3N disabled; LC3G4D4N disabled; LC3G4D1T disabled; LC3G4D2T disabled; LC3G4D3T disabled; LC3G4D4T disabled; 
    CLC3GLS3 = 0x00;
    // LC3EN enabled; INTN disabled; INTP disabled; MODE AND-OR; 
    CLC3CON = 0x80;
}

void init_CLC4()
{
    
}

bool getCLCout(byte clc)
{
    if(clc == 1)
        return(CLC1CONbits.LC1OUT);
    
    else if(clc == 2)
        return(CLC2CONbits.LC2OUT);
    
    else if(clc == 3)
        return(CLC3CONbits.LC3OUT);
    
    else if(clc == 4)
        return(CLC4CONbits.LC4OUT);
    
    else
        return 0;

}