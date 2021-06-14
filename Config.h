#ifndef CONFIG_H_
#define CONFIG_H_

#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "clock_config.h"
#include "pin_mux.h"
#include "fsl_common.h"
#include "MK64F12.h"

#define PIN0       	0u
#define PIN1       	1u
#define PIN2		2u
#define PIN3		3u
#define PIN10		10u
#define PIN11		11u

#define PIN4        4u
#define PIN6        6u

#define PIN22       22u
#define PIN21       21u
#define PIN26		26u

void GPIO_Config();

#endif /* CONFIG_H_ */
