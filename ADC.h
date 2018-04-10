#ifndef _ADC_H
#define _ADC_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


/**
  Section: Data Types Definitions
*/

/**
 *  result size of an A/D conversion
 */

typedef uint16_t adc_result_t;

/** ADC Channel Definition

 @Summary
   Defines the channels available for conversion.

 @Description
   This routine defines the channels that are available for the module to use.

 Remarks:
   None
 */

typedef enum
{
    channel_ANA2 =  0x2,
    channel_ANB1 =  0x9,
    channel_VSS =  0x3C,
    channel_Temp =  0x3D,
    channel_DAC1 =  0x3E,
    channel_FVR =  0x3F
} adcc_channel_t;

/**
  Section: ADC Module APIs
*/

/**
  @Summary
    Initializes the ADC

  @Description
    This routine initializes the Initializes the ADC.
    This routine must be called before any other ADC routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    convertedValue = ADC_GetSingleConversion();
    </code>
*/
void init_ADC(void);

/**
  @Summary
    Allows selection of a channel for conversion

  @Description
    This routine is used to select desired channel for conversion.
    available

  @Preconditions
    ADC_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    Pass in required channel number
    "For available channel refer to enum under adcc.h file"

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_StartConversion(AN1_Channel);
    convertedValue = ADC_GetConversionResult();
    </code>
*/
void ADC_StartConversion(adcc_channel_t channel);

/**
  @Summary
    Returns true when the conversion is completed otherwise false.

  @Description
    This routine is used to determine if conversion is completed.
    When conversion is complete routine returns true. It returns false otherwise.

  @Preconditions
    ADC_Initialize() and ADC_StartConversion(adcc_channel_t channel)
    function should have been called before calling this function.

  @Returns
    true  - If conversion is complete
    false - If conversion is not completed

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_StartConversion(AN1_Channel);

    while(!ADC_IsConversionDone());
    convertedValue = ADC_GetConversionResult();
    </code>
 */
bool ADC_IsConversionDone();

/**
  @Summary
    Returns the ADC conversion value.

  @Description
    This routine is used to get the analog to digital converted value. This
    routine gets converted values from the channel specified.

  @Preconditions
    This routine returns the conversion value only after the conversion is complete.
    Completion status can be checked using
    ADC_IsConversionDone() routine.

  @Returns
    Returns the converted value.

  @Param
    None

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
    ADC_StartConversion(AN1_Channel);

    while(ADC_IsConversionDone());

    convertedValue = ADC_GetConversionResult();
    </code>
 */
adc_result_t ADC_GetConversionResult(void);

/**
  @Summary
    Returns the ADC conversion value
    also allows selection of a channel for conversion.

  @Description
    This routine is used to select desired channel for conversion
    and to get the analog to digital converted value after a single conversion.

  @Preconditions
    ADC_Initialize() and ADC_DisableContinuousConversion() functions should have been called before calling this function.

  @Returns
    Returns the converted value.

  @Param
    Pass in required channel number.
    "For available channel refer to enum under adcc.h file"

  @Example
    <code>
    uint16_t convertedValue;

    ADC_Initialize();
	ADC_DisableContinuousConversion();
	
    convertedValue = ADC_GetSingleConversion(AN1_Channel);
    </code>
*/
adc_result_t ADC_GetSingleConversion(adcc_channel_t channel);

/**
  @Summary
    Stops the ADC conversion by resetting the ADGO bit.

  @Description
    None

  @Preconditions
    ADC_Initialize() and ADC_StartConversion() functions should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    ADC_Initialize();
	ADC_StartConversion();
	ADC_StopConversion();
    </code>
*/
void ADC_StopConversion(void);

/**
  @Summary
    Stops the ADC from automatic retriggering in continuous sampling mode

  @Description
    None

  @Preconditions
    ADC_Initialize() and ADC_EnableContinuousConversion() functions should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
        ADC_Initialize();
	ADC_EnableContinuousConversion();	
    </code>
*/
void ADC_SetStopOnInterrupt(void);

/**
  @Summary
    Discharges the input sample capacitor by setting the channel to AVss.

  @Description
    None

  @Preconditions
    None.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    </code>
*/
void ADC_DischargeSampleCapacitor(void); 

/**
  @Summary
    Loads the ADACQ register by the 8 bit value sent as argument.

  @Description
    None

  @Preconditions
    None.

  @Returns
    None

  @Param
    8 bit value to be set in the acquisition register.

  @Example
    <code>
	uint8_t acquisitionValue = 98;
	ADC_LoadAcquisitionRegister(acquisitionValue);
    </code>
*/
void ADC_LoadAcquisitionRegister(uint8_t);

/**
  @Summary
    Loads the ADPRE register by the 8 bit value sent as argument.

  @Description
    None

  @Preconditions
    None.

  @Returns
    None

  @Param
    8 bit value to be set in the precharge register.

  @Example
    <code>
	uint8_t prechargeTime = 98;
	ADC_SetPrechargeTime(prechargeTime);
    </code>
*/
void ADC_SetPrechargeTime(uint8_t);

/**
  @Summary
    Loads the ADRPT register by the 8 bit value sent as argument.

  @Description
    None

  @Preconditions
    None.

  @Returns
    None

  @Param
    8 bit value to be set in the Repeat register.

  @Example
    <code>
	uint8_t repeat = 98;
	ADC_SetRepeatCount(repeat);
    </code>
*/
void ADC_SetRepeatCount(uint8_t);

/**
  @Summary
    Returns the ADCNT register contents.

  @Description
    None

  @Preconditions
    None.

  @Returns
    Contents of ADCNT register

  @Param
    None.

  @Example
    <code>
	uint8_t count = ADC_GetCurrentCountofConversions();
	
    </code>
*/
uint8_t ADC_GetCurrentCountofConversions(void);

/**
  @Summary
    Clears the ADACLR bit.

  @Description
    None

  @Preconditions
    None.

  @Returns
    None

  @Param
    None.

  @Example
    <code>
	ADC_ClearAccumulator();
	
    </code>
*/
void ADC_ClearAccumulator(void);

/**
  @Summary
   Returns the 16 bit value obtained from ADACCH and ADACCL registers.

  @Description
    None

  @Preconditions
    None.

  @Returns
    16 bit value obtained from ADACCH and ADACCL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t accumulatorValue = ADC_GetAccumulatorValue();
	
    </code>
*/
uint16_t ADC_GetAccumulatorValue(void);

/**
  @Summary
   Returns the contents of ADAOV setting.

  @Description
    None

  @Preconditions
    None.

  @Returns
    Value of ADAOV bit.

  @Param
    None.

  @Example
    <code>
	bool accumulatorOverflow = ADC_HasAccumulatorOverflowed();
	
    </code>
*/
bool ADC_HasAccumulatorOverflowed(void);

/**
  @Summary
   Returns the contents of ADFLTRH and ADFLTRL registers.

  @Description
    None

  @Preconditions
    None.

  @Returns
    16 bit value obtained from ADFLTRH and ADFLTRL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t filterValue = ADC_GetFilterValue();
	
    </code>
*/
uint16_t ADC_GetFilterValue(void);

/**
  @Summary
   Returns the contents of ADPREVH and ADPREVL registers.

  @Description
    None

  @Preconditions
    None.

  @Returns
    16 bit value obtained from ADPREVH and ADPREVL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t prevResult = ADC_GetPreviousResult();
	
    </code>
*/
uint16_t ADC_GetPreviousResult(void);

/**
  @Summary
   Sets the ADSTPTH and ADSTPTL registers.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    16 bit value for set point.

  @Example
    <code>
	uint16_t setPoint = 90;
	ADC_DefineSetPoint(setPoint);
    </code>
*/
void ADC_DefineSetPoint(uint16_t);

/**
  @Summary
   Sets the ADUTHH and ADUTHL register.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    16 bit value for upper threshold.

  @Example
    <code>
	uint16_t upperThreshold = 90;
	ADC_SetUpperThreshold(upperThreshold);
	
    </code>
*/
void ADC_SetUpperThreshold(uint16_t);

/**
  @Summary
   Sets the ADLTHH and ADLTHL register.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    16 bit value for lower threshold..

  @Example
    <code>
	uint16_t lowerThreshold = 90;
	ADC_SetLowerThreshold(lowerThreshold);
	
    </code>
*/
void ADC_SetLowerThreshold(uint16_t);

/**
  @Summary
   Returns the 16 bit value obtained from ADERRH and ADERRL registers.

  @Description
    None

  @Preconditions
    None

  @Returns
    16 bit value obtained from ADERRH and ADERRL registers.

  @Param
    None.

  @Example
    <code>
	uint16_t error = ADC_GetErrorCalculation(void);
    </code>
*/
uint16_t ADC_GetErrorCalculation(void);

/**
  @Summary
   Sets the ADDSEN bit.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    None.

  @Example
    <code>
    </code>
*/
void ADC_EnableDoubleSampling(void);

/**
  @Summary
   Sets the ADCONT bit.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    None.

  @Example
    <code>
    </code>
*/
void ADC_EnableContinuousConversion(void);

/**
  @Summary
   Resets the ADCONT bit.

  @Description
    None

  @Preconditions
    None

  @Returns
    None

  @Param
    None.

  @Example
    <code>
    </code>
*/
void ADC_DisableContinuousConversion(void);

/**
  @Summary
   Returns the value of ADUTHR bit.

  @Description
    None

  @Preconditions
    None

  @Returns
    Returns the value of ADUTHR bit.

  @Param
    None.

  @Example
    <code>
    </code>
*/
bool ADC_HasErrorCrossedUpperThreshold(void);

/**
  @Summary
   Returns the value of ADLTHR bit.

  @Description
    None

  @Preconditions
    None

  @Returns
    Returns the value of ADLTHR bit.

  @Param
    None.

  @Example
    <code>
    </code>
*/
bool ADC_HasErrorCrossedLowerThreshold(void);

/**
  @Summary
   Returns value of ADSTAT setting.

  @Description
    None

  @Preconditions
    None

  @Returns
    Returns value of ADSTAT setting.

  @Param
    None.

  @Example
    <code>
    </code>
*/
uint8_t ADC_GetConversionStageStatus(void);


#endif	//_ADC_H

