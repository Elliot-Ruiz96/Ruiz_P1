#ifndef KEYBOARD_MATRIX_H_
#define KEYBOARD_MATRIX_H_

#include <stdio.h>
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "PIT.h"
#include "RGB.h"

typedef enum {
	FIRST,
	SECOND,
	THIRD,
	FOURTH,

}State_name_t1;

#define PIN0       	0u
#define PIN1       	1u
#define PIN2		2u
#define PIN3		3u
#define PIN10		10u
#define PIN11		11u

void Read_KeyPad();

uint32_t Get_Num();

#endif /* KEYBOARD_MATRIX_H_ */
