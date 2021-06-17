#ifndef DAC_H_
#define DAC_H_

#include "fsl_dac.h"
#include <stdio.h>

#define DAC_BASEADDR DAC0

void DAC_Config();
void DAC_Start(value);

#endif /* DAC_H_ */
