#ifndef STATES_H
#define	STATES_H

#include "config.h"

#include <xc.h>
#include <pic16f18877.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "ADC.h"
#include "CMP_DAC.h"
#include "TMR.h"


void voltmeter_state();

void capameter_state();
void printCapa();

void freqmeter_state();
void printFreq();

void counter_state();

void tempmeter_state();

void resmeter_state();

void pwm_state();

void ibtn_state();

#endif	/* STATES_H */

