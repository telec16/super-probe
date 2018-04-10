#ifndef CMP_DAC_H
#define	CMP_DAC_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"

void init_CMP_DAC();

//CMP1
inline bool getCMP1out(void);
void setCMP1InterruptHandler(void* InterruptHandler);
void setCMP1Interrupt(bool useInt);

//Do not call
void CMP1_ISR(void);

#endif	/* CMP_DAC_H */

