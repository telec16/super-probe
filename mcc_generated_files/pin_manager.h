/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18877
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()    do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()   do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()   do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()         PORTAbits.RA0
#define RA0_SetDigitalInput()   do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()  do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()     do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()   do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode() do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()    do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()   do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()   do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()         PORTAbits.RA1
#define RA1_SetDigitalInput()   do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()  do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()     do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()   do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode() do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set channel_ANA2 aliases
#define channel_ANA2_TRIS               TRISAbits.TRISA2
#define channel_ANA2_LAT                LATAbits.LATA2
#define channel_ANA2_PORT               PORTAbits.RA2
#define channel_ANA2_WPU                WPUAbits.WPUA2
#define channel_ANA2_OD                ODCONAbits.ODCA2
#define channel_ANA2_ANS                ANSELAbits.ANSA2
#define channel_ANA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_ANA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_ANA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_ANA2_GetValue()           PORTAbits.RA2
#define channel_ANA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_ANA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_ANA2_SetPullup()      do { WPUAbits.WPUA2 = 1; } while(0)
#define channel_ANA2_ResetPullup()    do { WPUAbits.WPUA2 = 0; } while(0)
#define channel_ANA2_SetPushPull()    do { ODCONAbits.ODCA2 = 1; } while(0)
#define channel_ANA2_SetOpenDrain()   do { ODCONAbits.ODCA2 = 0; } while(0)
#define channel_ANA2_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define channel_ANA2_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()    do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()   do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()   do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()         PORTAbits.RA3
#define RA3_SetDigitalInput()   do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()  do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()     do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()   do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode() do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()     do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()   do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode() do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set channel_ANB1 aliases
#define channel_ANB1_TRIS               TRISBbits.TRISB1
#define channel_ANB1_LAT                LATBbits.LATB1
#define channel_ANB1_PORT               PORTBbits.RB1
#define channel_ANB1_WPU                WPUBbits.WPUB1
#define channel_ANB1_OD                ODCONBbits.ODCB1
#define channel_ANB1_ANS                ANSELBbits.ANSB1
#define channel_ANB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define channel_ANB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define channel_ANB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define channel_ANB1_GetValue()           PORTBbits.RB1
#define channel_ANB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define channel_ANB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define channel_ANB1_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define channel_ANB1_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define channel_ANB1_SetPushPull()    do { ODCONBbits.ODCB1 = 1; } while(0)
#define channel_ANB1_SetOpenDrain()   do { ODCONBbits.ODCB1 = 0; } while(0)
#define channel_ANB1_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define channel_ANB1_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISBbits.TRISB5
#define IO_RB5_LAT                LATBbits.LATB5
#define IO_RB5_PORT               PORTBbits.RB5
#define IO_RB5_WPU                WPUBbits.WPUB5
#define IO_RB5_OD                ODCONBbits.ODCB5
#define IO_RB5_ANS                ANSELBbits.ANSB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()      do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()    do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()    do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetOpenDrain()   do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()  do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode() do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISBbits.TRISB6
#define IO_RB6_LAT                LATBbits.LATB6
#define IO_RB6_PORT               PORTBbits.RB6
#define IO_RB6_WPU                WPUBbits.WPUB6
#define IO_RB6_OD                ODCONBbits.ODCB6
#define IO_RB6_ANS                ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()      do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()    do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()    do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetOpenDrain()   do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetAnalogMode()  do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode() do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS               TRISBbits.TRISB7
#define IO_RB7_LAT                LATBbits.LATB7
#define IO_RB7_PORT               PORTBbits.RB7
#define IO_RB7_WPU                WPUBbits.WPUB7
#define IO_RB7_OD                ODCONBbits.ODCB7
#define IO_RB7_ANS                ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()      do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()    do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()    do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetOpenDrain()   do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetAnalogMode()  do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode() do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISCbits.TRISC0
#define IO_RC0_LAT                LATCbits.LATC0
#define IO_RC0_PORT               PORTCbits.RC0
#define IO_RC0_WPU                WPUCbits.WPUC0
#define IO_RC0_OD                ODCONCbits.ODCC0
#define IO_RC0_ANS                ANSELCbits.ANSC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()      do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()    do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()    do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetOpenDrain()   do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISCbits.TRISC1
#define IO_RC1_LAT                LATCbits.LATC1
#define IO_RC1_PORT               PORTCbits.RC1
#define IO_RC1_WPU                WPUCbits.WPUC1
#define IO_RC1_OD                ODCONCbits.ODCC1
#define IO_RC1_ANS                ANSELCbits.ANSC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()      do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()    do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()    do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetOpenDrain()   do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetAnalogMode()  do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode() do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS               TRISCbits.TRISC2
#define IO_RC2_LAT                LATCbits.LATC2
#define IO_RC2_PORT               PORTCbits.RC2
#define IO_RC2_WPU                WPUCbits.WPUC2
#define IO_RC2_OD                ODCONCbits.ODCC2
#define IO_RC2_ANS                ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()    do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetOpenDrain()   do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS               TRISCbits.TRISC3
#define IO_RC3_LAT                LATCbits.LATC3
#define IO_RC3_PORT               PORTCbits.RC3
#define IO_RC3_WPU                WPUCbits.WPUC3
#define IO_RC3_OD                ODCONCbits.ODCC3
#define IO_RC3_ANS                ANSELCbits.ANSC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_RC3_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_RC3_SetPushPull()    do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_RC3_SetOpenDrain()   do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_RC3_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS               TRISCbits.TRISC4
#define IO_RC4_LAT                LATCbits.LATC4
#define IO_RC4_PORT               PORTCbits.RC4
#define IO_RC4_WPU                WPUCbits.WPUC4
#define IO_RC4_OD                ODCONCbits.ODCC4
#define IO_RC4_ANS                ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()    do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetOpenDrain()   do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetAnalogMode()  do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode() do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RC5 aliases
#define IO_RC5_TRIS               TRISCbits.TRISC5
#define IO_RC5_LAT                LATCbits.LATC5
#define IO_RC5_PORT               PORTCbits.RC5
#define IO_RC5_WPU                WPUCbits.WPUC5
#define IO_RC5_OD                ODCONCbits.ODCC5
#define IO_RC5_ANS                ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()    do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetOpenDrain()   do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetAnalogMode()  do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode() do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_RC6 aliases
#define IO_RC6_TRIS               TRISCbits.TRISC6
#define IO_RC6_LAT                LATCbits.LATC6
#define IO_RC6_PORT               PORTCbits.RC6
#define IO_RC6_WPU                WPUCbits.WPUC6
#define IO_RC6_OD                ODCONCbits.ODCC6
#define IO_RC6_ANS                ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()      do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_RC6_ResetPullup()    do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_RC6_SetPushPull()    do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_RC6_SetOpenDrain()   do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_RC6_SetAnalogMode()  do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode() do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_RC7 aliases
#define IO_RC7_TRIS               TRISCbits.TRISC7
#define IO_RC7_LAT                LATCbits.LATC7
#define IO_RC7_PORT               PORTCbits.RC7
#define IO_RC7_WPU                WPUCbits.WPUC7
#define IO_RC7_OD                ODCONCbits.ODCC7
#define IO_RC7_ANS                ANSELCbits.ANSC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()      do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()    do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_RC7_SetPushPull()    do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_RC7_SetOpenDrain()   do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_RC7_SetAnalogMode()  do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode() do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS               TRISDbits.TRISD0
#define IO_RD0_LAT                LATDbits.LATD0
#define IO_RD0_PORT               PORTDbits.RD0
#define IO_RD0_WPU                WPUDbits.WPUD0
#define IO_RD0_OD                ODCONDbits.ODCD0
#define IO_RD0_ANS                ANSELDbits.ANSD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()      do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()    do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()    do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetOpenDrain()   do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetAnalogMode()  do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode() do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISDbits.TRISD1
#define IO_RD1_LAT                LATDbits.LATD1
#define IO_RD1_PORT               PORTDbits.RD1
#define IO_RD1_WPU                WPUDbits.WPUD1
#define IO_RD1_OD                ODCONDbits.ODCD1
#define IO_RD1_ANS                ANSELDbits.ANSD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()      do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()    do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()    do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetOpenDrain()   do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetAnalogMode()  do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode() do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS               TRISDbits.TRISD2
#define IO_RD2_LAT                LATDbits.LATD2
#define IO_RD2_PORT               PORTDbits.RD2
#define IO_RD2_WPU                WPUDbits.WPUD2
#define IO_RD2_OD                ODCONDbits.ODCD2
#define IO_RD2_ANS                ANSELDbits.ANSD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetPullup()      do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_RD2_ResetPullup()    do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_RD2_SetPushPull()    do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_RD2_SetOpenDrain()   do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_RD2_SetAnalogMode()  do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode() do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS               TRISDbits.TRISD3
#define IO_RD3_LAT                LATDbits.LATD3
#define IO_RD3_PORT               PORTDbits.RD3
#define IO_RD3_WPU                WPUDbits.WPUD3
#define IO_RD3_OD                ODCONDbits.ODCD3
#define IO_RD3_ANS                ANSELDbits.ANSD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()      do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()    do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()    do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetOpenDrain()   do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetAnalogMode()  do { ANSELDbits.ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode() do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IO_RD4 aliases
#define IO_RD4_TRIS               TRISDbits.TRISD4
#define IO_RD4_LAT                LATDbits.LATD4
#define IO_RD4_PORT               PORTDbits.RD4
#define IO_RD4_WPU                WPUDbits.WPUD4
#define IO_RD4_OD                ODCONDbits.ODCD4
#define IO_RD4_ANS                ANSELDbits.ANSD4
#define IO_RD4_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define IO_RD4_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define IO_RD4_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define IO_RD4_GetValue()           PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define IO_RD4_SetPullup()      do { WPUDbits.WPUD4 = 1; } while(0)
#define IO_RD4_ResetPullup()    do { WPUDbits.WPUD4 = 0; } while(0)
#define IO_RD4_SetPushPull()    do { ODCONDbits.ODCD4 = 1; } while(0)
#define IO_RD4_SetOpenDrain()   do { ODCONDbits.ODCD4 = 0; } while(0)
#define IO_RD4_SetAnalogMode()  do { ANSELDbits.ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode() do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_RD5 aliases
#define IO_RD5_TRIS               TRISDbits.TRISD5
#define IO_RD5_LAT                LATDbits.LATD5
#define IO_RD5_PORT               PORTDbits.RD5
#define IO_RD5_WPU                WPUDbits.WPUD5
#define IO_RD5_OD                ODCONDbits.ODCD5
#define IO_RD5_ANS                ANSELDbits.ANSD5
#define IO_RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define IO_RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define IO_RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define IO_RD5_GetValue()           PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define IO_RD5_SetPullup()      do { WPUDbits.WPUD5 = 1; } while(0)
#define IO_RD5_ResetPullup()    do { WPUDbits.WPUD5 = 0; } while(0)
#define IO_RD5_SetPushPull()    do { ODCONDbits.ODCD5 = 1; } while(0)
#define IO_RD5_SetOpenDrain()   do { ODCONDbits.ODCD5 = 0; } while(0)
#define IO_RD5_SetAnalogMode()  do { ANSELDbits.ANSD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode() do { ANSELDbits.ANSD5 = 0; } while(0)

// get/set IO_RD6 aliases
#define IO_RD6_TRIS               TRISDbits.TRISD6
#define IO_RD6_LAT                LATDbits.LATD6
#define IO_RD6_PORT               PORTDbits.RD6
#define IO_RD6_WPU                WPUDbits.WPUD6
#define IO_RD6_OD                ODCONDbits.ODCD6
#define IO_RD6_ANS                ANSELDbits.ANSD6
#define IO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_GetValue()           PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_SetPullup()      do { WPUDbits.WPUD6 = 1; } while(0)
#define IO_RD6_ResetPullup()    do { WPUDbits.WPUD6 = 0; } while(0)
#define IO_RD6_SetPushPull()    do { ODCONDbits.ODCD6 = 1; } while(0)
#define IO_RD6_SetOpenDrain()   do { ODCONDbits.ODCD6 = 0; } while(0)
#define IO_RD6_SetAnalogMode()  do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode() do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set IO_RD7 aliases
#define IO_RD7_TRIS               TRISDbits.TRISD7
#define IO_RD7_LAT                LATDbits.LATD7
#define IO_RD7_PORT               PORTDbits.RD7
#define IO_RD7_WPU                WPUDbits.WPUD7
#define IO_RD7_OD                ODCONDbits.ODCD7
#define IO_RD7_ANS                ANSELDbits.ANSD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()      do { WPUDbits.WPUD7 = 1; } while(0)
#define IO_RD7_ResetPullup()    do { WPUDbits.WPUD7 = 0; } while(0)
#define IO_RD7_SetPushPull()    do { ODCONDbits.ODCD7 = 1; } while(0)
#define IO_RD7_SetOpenDrain()   do { ODCONDbits.ODCD7 = 0; } while(0)
#define IO_RD7_SetAnalogMode()  do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode() do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set IO_RE1 aliases
#define IO_RE1_TRIS               TRISEbits.TRISE1
#define IO_RE1_LAT                LATEbits.LATE1
#define IO_RE1_PORT               PORTEbits.RE1
#define IO_RE1_WPU                WPUEbits.WPUE1
#define IO_RE1_OD                ODCONEbits.ODCE1
#define IO_RE1_ANS                ANSELEbits.ANSE1
#define IO_RE1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define IO_RE1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define IO_RE1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define IO_RE1_GetValue()           PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define IO_RE1_SetPullup()      do { WPUEbits.WPUE1 = 1; } while(0)
#define IO_RE1_ResetPullup()    do { WPUEbits.WPUE1 = 0; } while(0)
#define IO_RE1_SetPushPull()    do { ODCONEbits.ODCE1 = 1; } while(0)
#define IO_RE1_SetOpenDrain()   do { ODCONEbits.ODCE1 = 0; } while(0)
#define IO_RE1_SetAnalogMode()  do { ANSELEbits.ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode() do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set IO_RE2 aliases
#define IO_RE2_TRIS               TRISEbits.TRISE2
#define IO_RE2_LAT                LATEbits.LATE2
#define IO_RE2_PORT               PORTEbits.RE2
#define IO_RE2_WPU                WPUEbits.WPUE2
#define IO_RE2_OD                ODCONEbits.ODCE2
#define IO_RE2_ANS                ANSELEbits.ANSE2
#define IO_RE2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define IO_RE2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define IO_RE2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define IO_RE2_GetValue()           PORTEbits.RE2
#define IO_RE2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define IO_RE2_SetPullup()      do { WPUEbits.WPUE2 = 1; } while(0)
#define IO_RE2_ResetPullup()    do { WPUEbits.WPUE2 = 0; } while(0)
#define IO_RE2_SetPushPull()    do { ODCONEbits.ODCE2 = 1; } while(0)
#define IO_RE2_SetOpenDrain()   do { ODCONEbits.ODCE2 = 0; } while(0)
#define IO_RE2_SetAnalogMode()  do { ANSELEbits.ANSE2 = 1; } while(0)
#define IO_RE2_SetDigitalMode() do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/