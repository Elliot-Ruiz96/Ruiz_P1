#ifndef RGB_H_
#define RGB_H_

#include "fsl_gpio.h"

#define PIN22       22u
#define PIN21       21u
#define PIN26		26u

#define CORE_FREQ	10000000u
#define DELAY		1000000u

void RED_RGB();
void GREEN_RGB();
void BLUE_RGB();
void PURPLE_RGB();
void YELLOW_RGB();
void LIGHTBLUE_RGB();
void WHITE_RGB();
void OFF_RGB();

#endif /* RGB_H_ */
