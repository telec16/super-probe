#include "ADC.h"

void init_ADC(void)
{
    // set the ADC to the options selected in the User Interface
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL VSS; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Basic_mode; ADACLR disabled; ADPSIS ADFLTR; 
    ADCON2 = 0x00;
    // ADCALC Actual result vs filtered value; ADTMD disabled; ADSOI ADGO not cleared; 
    ADCON3 = 0x20;
    // ADACT disabled; 
    ADACT = 0x00;
    // ADAOV ACC or ADERR not Overflowed; 
    ADSTAT = 0x00;
    // ADCS FOSC/32; 
    ADCLK = 0x0F;
    // ADNREF VSS; ADPREF VDD; 
    ADREF = 0x00;
    // ADCAP 0; 
    ADCAP = 0x00;
    // ADPRE 0; 
    ADPRE = 0x00;
    // ADACQ 2; 
    ADACQ = 0x02;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADRPT 0; 
    ADRPT = 0x00;
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    
    // ADGO stop; ADFM right; ADON enabled; ADCONT enabled; ADCS FOSC/ADCLK; 
    ADCON0 = 0xC4;
    

}

void ADC_StartConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;  
  
    // Turn on the ADC module
    ADCON0bits.ADON = 1;      

    // Start the conversion
    ADCON0bits.ADGO = 1;
}

bool ADC_IsConversionDone()
{
    // Start the conversion
    return (!ADCON0bits.ADGO);
}

adc_result_t ADC_GetConversionResult(void)
{
    // Return the result
    return ((ADRESH << 8) + ADRESL);
}

adc_result_t ADC_GetSingleConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;
	
    //Disable the continuous mode.
    ADCON0bits.ADCONT = 0;    

    // Start the conversion
    ADCON0bits.ADGO = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.ADGO)
    {
    }

    // Conversion finished, return the result
    return ((ADRESH << 8) + ADRESL);
}

void ADC_StopConversion(void)
{
	//Reset the ADGO bit.
	ADCON0bits.ADGO = 0;
}

void ADC_SetStopOnInterrupt(void)
{
	//Set the ADSOI bit.
	ADCON3bits.ADSOI = 1;
}

void ADC_DischargeSampleCapacitor(void)
{
	//Set the ADC channel to AVss.
	ADPCH = 0x3C;   
}

void ADC_LoadAcquisitionRegister(uint8_t acquisitionValue)
{
	//Load the ADACQ register.
	ADACQ = acquisitionValue;   
}

void ADC_SetPrechargeTime(uint8_t prechargeTime)
{
	//Load the ADPRE register.
	ADPRE = prechargeTime;  
}

void ADC_SetRepeatCount(uint8_t repeatCount)
{
	//Load the ADRPT register.
	ADRPT = repeatCount;   
}

uint8_t ADC_GetCurrentCountofConversions(void)
{
	//Return the contents of ADCNT register
	return ADCNT;
}

void ADC_ClearAccumulator(void)
{
	//Reset the ADCON2bits.ADACLR bit.
	ADCON2bits.ADACLR = 1;
}

uint16_t ADC_GetAccumulatorValue(void)
{
	//Return the contents of ADACCH and ADACCL registers
	return ((ADACCH << 8) + ADACCL);
}

bool ADC_HasAccumulatorOverflowed(void)
{
	//Return the status of ADSTATbits.ADAOV
	return ADSTATbits.ADAOV;
}

uint16_t ADC_GetFilterValue(void)
{
	//Return the contents of ADFLTRH and ADFLTRL registers
	return ((ADFLTRH << 8) + ADFLTRL);
}

uint16_t ADC_GetPreviousResult(void)
{
	//Return the contents of ADPREVH and ADPREVL registers
	return ((ADPREVH << 8) + ADPREVL);
}

void ADC_DefineSetPoint(uint16_t setPoint)
{
	//Sets the ADSTPTH and ADSTPTL registers
	ADSTPTH = setPoint >> 8;
	ADSTPTL = setPoint;
}

void ADC_SetUpperThreshold(uint16_t upperThreshold)
{
	//Sets the ADUTHH and ADUTHL registers
	ADUTHH = upperThreshold >> 8;
	ADUTHL = upperThreshold;
}

void ADC_SetLowerThreshold(uint16_t lowerThreshold)
{
	//Sets the ADLTHH and ADLTHL registers
	ADLTHH = lowerThreshold >> 8;
	ADLTHL = lowerThreshold;
}

uint16_t ADC_GetErrorCalculation(void)
{
	//Return the contents of ADERRH and ADERRL registers
	return ((ADERRH << 8) + ADERRL);
}

void ADC_EnableDoubleSampling(void)
{
	//Sets the ADCON1bits.ADDSEN
	ADCON1bits.ADDSEN = 1;
}

void ADC_EnableContinuousConversion(void)
{
	//Sets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 1;
}

void ADC_DisableContinuousConversion(void)
{
	//Resets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 0;
}

bool ADC_HasErrorCrossedUpperThreshold(void)
{
	//Returns the value of ADSTATbits.ADUTHR bit.
	return ADSTATbits.ADUTHR;
}

bool ADC_HasErrorCrossedLowerThreshold(void)
{
	//Returns the value of ADSTATbits.ADLTHR bit.
	return ADSTATbits.ADLTHR;
}

uint8_t ADC_GetConversionStageStatus(void)
{
	//Returns the contents of ADSTATbits.ADSTAT field.
	return ADSTATbits.ADSTAT;
}

void ADC_never_called(void){
    ADC_StartConversion(0);
    ADC_IsConversionDone();
    ADC_GetAccumulatorValue();
    ADC_StopConversion();
    ADC_SetStopOnInterrupt();
    ADC_DischargeSampleCapacitor();
    ADC_LoadAcquisitionRegister(0);
    ADC_SetPrechargeTime(0);
    ADC_SetRepeatCount(0);
    ADC_GetCurrentCountofConversions();
    ADC_ClearAccumulator();
    ADC_GetAccumulatorValue();
    ADC_HasAccumulatorOverflowed();
    ADC_GetFilterValue();
    ADC_GetPreviousResult();
    ADC_DefineSetPoint(0);
    ADC_SetUpperThreshold(0);
    ADC_SetLowerThreshold(0);
    ADC_GetErrorCalculation();
    ADC_EnableDoubleSampling();
    ADC_EnableContinuousConversion();
    ADC_DisableContinuousConversion();
    ADC_HasErrorCrossedUpperThreshold();
    ADC_HasErrorCrossedLowerThreshold();
    ADC_GetConversionStageStatus();
    
    ADC_never_called();
}


/**
 End of File
*/
